#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
交互式文件名清理工具
提供图形化交互界面
"""

import os
import re
import sys
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from pathlib import Path

class FileRenamerGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("文件名清理工具")
        self.root.geometry("600x500")
        
        # 变量
        self.directory = tk.StringVar(value=os.getcwd())
        self.pattern = tk.StringVar(value="*")
        self.chars_to_remove = tk.StringVar(value=" ()")
        self.replace_with = tk.StringVar(value="")
        self.recursive = tk.BooleanVar(value=False)
        self.preview_mode = tk.BooleanVar(value=True)
        
        # 创建界面
        self.create_widgets()
        
        # 初始化预览
        self.update_preview()
    
    def create_widgets(self):
        # 创建主框架
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # 目录选择
        ttk.Label(main_frame, text="目标目录:").grid(row=0, column=0, sticky=tk.W, pady=5)
        dir_entry = ttk.Entry(main_frame, textvariable=self.directory, width=50)
        dir_entry.grid(row=0, column=1, padx=5, pady=5)
        ttk.Button(main_frame, text="浏览...", command=self.browse_directory).grid(row=0, column=2, padx=5, pady=5)
        
        # 文件模式
        ttk.Label(main_frame, text="文件模式:").grid(row=1, column=0, sticky=tk.W, pady=5)
        ttk.Entry(main_frame, textvariable=self.pattern, width=50).grid(row=1, column=1, padx=5, pady=5)
        
        # 要移除的字符
        ttk.Label(main_frame, text="移除字符:").grid(row=2, column=0, sticky=tk.W, pady=5)
        ttk.Entry(main_frame, textvariable=self.chars_to_remove, width=50).grid(row=2, column=1, padx=5, pady=5)
        
        # 替换为
        ttk.Label(main_frame, text="替换为:").grid(row=3, column=0, sticky=tk.W, pady=5)
        ttk.Entry(main_frame, textvariable=self.replace_with, width=50).grid(row=3, column=1, padx=5, pady=5)
        
        # 预设字符按钮
        preset_frame = ttk.Frame(main_frame)
        preset_frame.grid(row=4, column=1, sticky=tk.W, pady=5)
        
        presets = [
            ("空格和括号", " ()"),
            ("仅空格", " "),
            ("仅括号", "()"),
            ("特殊字符", "!@#$%^&*"),
            ("标点符号", ".,;:!?")
        ]
        
        for i, (text, chars) in enumerate(presets):
            ttk.Button(preset_frame, text=text, width=10,
                      command=lambda c=chars: self.set_chars(c)).grid(row=0, column=i, padx=2)
        
        # 选项
        options_frame = ttk.Frame(main_frame)
        options_frame.grid(row=5, column=1, sticky=tk.W, pady=10)
        
        ttk.Checkbutton(options_frame, text="递归处理子目录", 
                       variable=self.recursive).grid(row=0, column=0, sticky=tk.W)
        ttk.Checkbutton(options_frame, text="预览模式", 
                       variable=self.preview_mode).grid(row=0, column=1, sticky=tk.W, padx=20)
        
        # 预览按钮
        ttk.Button(main_frame, text="更新预览", command=self.update_preview).grid(row=6, column=1, pady=10)
        
        # 预览区域
        ttk.Label(main_frame, text="预览:").grid(row=7, column=0, sticky=tk.W, pady=5)
        
        # 创建带滚动条的文本框
        preview_frame = ttk.Frame(main_frame)
        preview_frame.grid(row=8, column=0, columnspan=3, sticky=(tk.W, tk.E, tk.N, tk.S), pady=5)
        
        # 滚动条
        scrollbar = ttk.Scrollbar(preview_frame)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # 文本框
        self.preview_text = tk.Text(preview_frame, height=10, width=70, yscrollcommand=scrollbar.set)
        self.preview_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.config(command=self.preview_text.yview)
        
        # 按钮框架
        button_frame = ttk.Frame(main_frame)
        button_frame.grid(row=9, column=0, columnspan=3, pady=10)
        
        ttk.Button(button_frame, text="执行重命名", command=self.execute_rename).pack(side=tk.LEFT, padx=5)
        ttk.Button(button_frame, text="导出列表", command=self.export_list).pack(side=tk.LEFT, padx=5)
        ttk.Button(button_frame, text="退出", command=self.root.quit).pack(side=tk.LEFT, padx=5)
        
        # 配置网格权重
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=1)
        main_frame.rowconfigure(8, weight=1)
    
    def browse_directory(self):
        """浏览目录"""
        directory = filedialog.askdirectory(initialdir=self.directory.get())
        if directory:
            self.directory.set(directory)
            self.update_preview()
    
    def set_chars(self, chars):
        """设置预设字符"""
        self.chars_to_remove.set(chars)
        self.update_preview()
    
    def update_preview(self):
        """更新预览"""
        self.preview_text.delete(1.0, tk.END)
        
        directory = self.directory.get()
        pattern = self.pattern.get()
        chars_to_remove = self.chars_to_remove.get()
        replace_with = self.replace_with.get()
        recursive = self.recursive.get()
        
        if not os.path.isdir(directory):
            self.preview_text.insert(tk.END, "错误: 目录不存在\n")
            return
        
        # 收集文件
        files = self.collect_files(directory, pattern, recursive)
        
        if not files:
            self.preview_text.insert(tk.END, "未找到匹配的文件\n")
            return
        
        self.preview_text.insert(tk.END, f"找到 {len(files)} 个文件:\n")
        self.preview_text.insert(tk.END, "="*60 + "\n")
        
        # 预览重命名
        renamed_count = 0
        
        for filepath in files[:50]:  # 只显示前50个
            filename = os.path.basename(filepath)
            
            # 清理文件名
            cleaned = filename
            for char in chars_to_remove:
                cleaned = cleaned.replace(char, replace_with)
            
            if filename != cleaned:
                self.preview_text.insert(tk.END, f"{filename} -> {cleaned}\n")
                renamed_count += 1
        
        if len(files) > 50:
            self.preview_text.insert(tk.END, f"... 还有 {len(files) - 50} 个文件\n")
        
        self.preview_text.insert(tk.END, "="*60 + "\n")
        self.preview_text.insert(tk.END, f"将重命名 {renamed_count} 个文件\n")
    
    def collect_files(self, directory, pattern, recursive):
        """收集匹配的文件"""
        import fnmatch
        
        files = []
        
        if recursive:
            for root, dirs, filenames in os.walk(directory):
                for filename in filenames:
                    if fnmatch.fnmatch(filename, pattern) or pattern == "*":
                        files.append(os.path.join(root, filename))
        else:
            for filename in os.listdir(directory):
                filepath = os.path.join(directory, filename)
                if os.path.isfile(filepath) and (fnmatch.fnmatch(filename, pattern) or pattern == "*"):
                    files.append(filepath)
        
        return files
    
    def execute_rename(self):
        """执行重命名"""
        if not messagebox.askyesno("确认", "确定要执行重命名吗？"):
            return
        
        directory = self.directory.get()
        pattern = self.pattern.get()
        chars_to_remove = self.chars_to_remove.get()
        replace_with = self.replace_with.get()
        recursive = self.recursive.get()
        
        if not os.path.isdir(directory):
            messagebox.showerror("错误", "目录不存在")
            return
        
        # 收集文件
        files = self.collect_files(directory, pattern, recursive)
        
        if not files:
            messagebox.showinfo("信息", "未找到匹配的文件")
            return
        
        # 执行重命名
        renamed = 0
        errors = 0
        
        for filepath in files:
            filename = os.path.basename(filepath)
            dirname = os.path.dirname(filepath)
            
            # 清理文件名
            cleaned = filename
            for char in chars_to_remove:
                cleaned = cleaned.replace(char, replace_with)
            
            if filename != cleaned:
                new_path = os.path.join(dirname, cleaned)
                
                # 检查是否与现有文件冲突
                if os.path.exists(new_path):
                    errors += 1
                    continue
                
                try:
                    os.rename(filepath, new_path)
                    renamed += 1
                except Exception as e:
                    errors += 1
        
        # 显示结果
        messagebox.showinfo("完成", 
                          f"重命名完成!\n\n"
                          f"总文件: {len(files)}\n"
                          f"成功重命名: {renamed}\n"
                          f"错误/跳过: {errors}")
        
        # 更新预览
        self.update_preview()
    
    def export_list(self):
        """导出重命名列表"""
        directory = self.directory.get()
        pattern = self.pattern.get()
        chars_to_remove = self.chars_to_remove.get()
        replace_with = self.replace_with.get()
        recursive = self.recursive.get()
        
        if not os.path.isdir(directory):
            messagebox.showerror("错误", "目录不存在")
            return
        
        # 选择保存位置
        save_path = filedialog.asksaveasfilename(
            defaultextension=".txt",
            filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
        )
        
        if not save_path:
            return
        
        # 收集文件
        files = self.collect_files(directory, pattern, recursive)
        
        # 写入文件
        with open(save_path, 'w', encoding='utf-8') as f:
            f.write(f"文件名重命名列表\n")
            f.write(f"目录: {directory}\n")
            f.write(f"模式: {pattern}\n")
            f.write(f"移除字符: {chars_to_remove}\n")
            f.write(f"替换为: {replace_with}\n")
            f.write(f"递归: {recursive}\n")
            f.write("="*60 + "\n\n")
            
            renamed_count = 0
            
            for filepath in files:
                filename = os.path.basename(filepath)
                
                # 清理文件名
                cleaned = filename
                for char in chars_to_remove:
                    cleaned = cleaned.replace(char, replace_with)
                
                if filename != cleaned:
                    f.write(f"{filename} -> {cleaned}\n")
                    renamed_count += 1
            
            f.write("\n" + "="*60 + "\n")
            f.write(f"总文件数: {len(files)}\n")
            f.write(f"将重命名: {renamed_count}\n")
        
        messagebox.showinfo("导出完成", f"列表已导出到: {save_path}")

def main():
    """主函数"""
    root = tk.Tk()
    app = FileRenamerGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()