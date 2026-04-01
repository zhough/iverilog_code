import os

# 配置
COE_FOLDER   = "./rv32i_v3/coe"      # coe 所在文件夹（当前目录）
OUT_FOLDER   = "./rv32i_v3/hex"    # 输出 hex 的文件夹（自动创建）

# 创建输出文件夹
if not os.path.exists(OUT_FOLDER):
    os.mkdir(OUT_FOLDER)

# 遍历所有 coe 文件
for fname in os.listdir(COE_FOLDER):
    if not fname.endswith(".coe"):
        continue

    coe_path = os.path.join(COE_FOLDER, fname)
    hex_path = os.path.join(OUT_FOLDER, fname.replace(".coe", ".hex"))

    try:
        with open(coe_path, "r") as f:
            lines = f.readlines()

        hex_lines = []
        in_vector = False

        for line in lines:
            line = line.strip()

            # 找到数据开始
            if "memory_initialization_vector" in line:
                in_vector = True
                continue

            if not in_vector:
                continue

            # 清理符号
            line = line.replace(",", "").replace(";", "").strip()
            if line:
                hex_lines.append(line)

        # 写入 hex
        with open(hex_path, "w") as f:
            f.write("\n".join(hex_lines))

        print(f"✅ 转换成功：{fname} → {hex_path}")

    except Exception as e:
        print(f"❌ 失败：{fname}，原因：{e}")

print("\n🎉 全部完成！所有 hex 在【hex】文件夹里！")