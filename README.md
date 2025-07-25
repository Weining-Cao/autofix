---

## 🛠 autofix

自动修复无法编译的 `.c` 文件

---

### ✨ 功能

* 递归查找所有 `.c` 文件；
* 使用 `gcc` 编译；
* 编译失败时调用 DeepSeek 修复（最多尝试 3 次）；
* 修复失败后终止并输出错误信息。

---

### ✅ 使用步骤

1. 安装依赖：

   ```bash
   pip install openai
   ```

2. 设置 API 密钥：

   ```bash
   export DEEPSEEK_API_KEY="sk-xxxxxxxx"
   source ~/.bashrc  # 或 ~/.zshrc
   ```

3. 执行脚本：

   ```bash
   python3 autofix.py
   ```

---

附带Code2Inv数据集的修复结果

---
