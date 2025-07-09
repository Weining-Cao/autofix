import subprocess
import os
import sys
from openai import OpenAI

# 初始化 DeepSeek API 客户端
client = OpenAI(
    api_key=os.getenv("DEEPSEEK_API_KEY"),
    base_url="https://api.deepseek.com/v1"
)

MODEL_NAME = "deepseek-coder"

def compile_c_file(filename, output):
    result = subprocess.run(
        ["gcc", filename, "-o", output],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    return result.returncode == 0, result.stderr

def call_deepseek_fix(code, error):
    system_prompt = "你是一个精通 C 语言的编程专家。用户会给出一段无法通过 gcc 编译的 C 代码，请你修复它，使其完整且能编译通过。不要添加解释或注释。"

    user_prompt = f"""以下 C 代码无法通过 gcc 编译，请修复它：
---- 代码 ----
{code}
---- 编译错误 ----
{error}
---- 要求 ----
请返回完整的、可编译的 C 代码，必须包含 main 函数，不要包含 markdown、注释或解释。
"""

    try:
        response = client.chat.completions.create(
            model=MODEL_NAME,
            messages=[
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": user_prompt}
            ]
        )

        content = response.choices[0].message.content.strip()

        if not content:
            print("❌ DeepSeek API 返回空内容，终止程序。")
            sys.exit(1)

        if content.startswith("```"):
            parts = content.split("```")
            if len(parts) >= 2:
                content = parts[1]
                if content.startswith("c"):
                    content = content[1:].lstrip()

        return content

    except Exception as e:
        print(f"❌ DeepSeek API 请求失败: {e}")
        sys.exit(1)

# 收集所有 .c 文件路径
c_files = []
for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".c"):
            full_path = os.path.join(root, file)
            c_files.append(full_path)

# 排序处理（按路径名）
c_files.sort()

# 遍历每个 .c 文件进行编译与修复
for filepath in c_files:
    output = os.path.splitext(filepath)[0] + ".out"

    try:
        success, error = compile_c_file(filepath, output)

        if success:
            print(f"✅ 编译成功: {filepath}")
            if os.path.exists(output):
                os.remove(output)
            continue

        with open(filepath, 'r', encoding='utf-8') as f:
            original_code = f.read()

        print(f"\n❌ 编译失败: {filepath}")
        print("---- 错误信息 ----")
        print(error.strip())

        # 多次尝试修复
        fixed_code = original_code
        max_attempts = 3

        for attempt in range(1, max_attempts + 1):
            print(f"🤖 第 {attempt} 次调用 DeepSeek 修复代码...")
            fixed_code = call_deepseek_fix(fixed_code, error)

            if not fixed_code.strip():
                print("❌ 修复代码为空，终止程序。")
                sys.exit(1)

            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(fixed_code)

            success, error = compile_c_file(filepath, output)

            if success:
                print(f"✅ 第 {attempt} 次修复后编译成功: {filepath}")
                if os.path.exists(output):
                    os.remove(output)
                break
            else:
                print(f"⚠️ 第 {attempt} 次修复后仍然无法编译。")

        if not success:
            print(f"❌ 修复尝试失败 {max_attempts} 次，放弃处理: {filepath}")
            print("---- 最终修复代码 ----")
            print(fixed_code)
            print("---- 编译错误信息 ----")
            print(error.strip())
            sys.exit(1)

    except FileNotFoundError:
        print(f"⚠️ 文件未找到: {filepath}，跳过")
    except Exception as e:
        print(f"⚠️ 处理 {filepath} 时发生异常: {e}")
        sys.exit(1)
