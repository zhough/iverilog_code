import os

# ===== 在这里修改文件路径 =====
INPUT_FILE = "irom.hex"      # 输入的 .hex 文件
OUTPUT_FILE = "src0.bin"     # 输出的 .bin 文件
# =============================

with open(INPUT_FILE, 'r') as f:
    hex_data = []
    for line in f:
        line_clean = line.strip()
        if line_clean and not line_clean.startswith('#'):
            hex_data.append(line_clean)

hex_string = ''.join(hex_data)
if len(hex_string) % 2 != 0:
    hex_string += '0'

binary_data = bytes.fromhex(hex_string)

with open(OUTPUT_FILE, 'wb') as f:
    f.write(binary_data)

print(f"完成: {INPUT_FILE} -> {OUTPUT_FILE} ({len(binary_data)} 字节)")