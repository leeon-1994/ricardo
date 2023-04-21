from PIL import Image
import os


# 设置图片像素常量
SQUARE_FIT_SIZE = 300
# 设置水印常量
LOGO_FILENAME = 'catlogo.png'

# 打开水印文件
logo_img = Image.open(LOGO_FILENAME)
# 获取宽高
logowidth, logoheight = logo_img.size

# 新建文件夹，存放生成水印图像
os.makedirs('logo', exist_ok=True)

# 遍历当前目录
for filename in os.listdir('.'):
    # 如果包含.jpg & .png & 水印图像, 则跳过
    if not (filename.endswith('.jpg') or filename.endswith('.png') or filename == LOGO_FILENAME):
        continue
    img = Image.open(filename)
    width, height = img.size
    # 调整图片大小
    if width > SQUARE_FIT_SIZE and height > SQUARE_FIT_SIZE:
        if width > height:
            height = int((SQUARE_FIT_SIZE / width) * height)
            width = SQUARE_FIT_SIZE
        else:
            width = int((SQUARE_FIT_SIZE / height) * width)
            height = SQUARE_FIT_SIZE
        print('Resizing %s...' % (filename))
        img = img.resize(width, height)

# 添加logo
print('Adding logo to %s...' % (filename))
img.paste(logo_img, (width - logowidth, height - logoheight), logo_img)

img.save(os.path.join('logo', filename))
