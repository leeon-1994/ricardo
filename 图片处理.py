from PIL import Image, ImageColor
import os
# 获取颜色RGB值
color_RGB = ImageColor.getcolor('red', "RGBA")

img = Image.open('img/jxm.webp')
size = img.size
name = img.filename
fmt = img.format
width, height = img.size

# 复制
copy_img = img.copy()
# 剪裁
crop_img = copy_img.crop((0, 0, 100, 100))
# crop_img.save('img/jxm_copy.png')
# os.unlink('img/jxm_copy.png') 删除

# 新建图像
new_img = Image.new('RGBA', (100,100), 'white')
# new_img.save('img/white.png')

# 粘贴图像
cutImg = Image.open('img/white.png')
cutImgCopy = cutImg.copy()
# img.paste(cutImgCopy, (0,0))
# img.save('img/paste.png')

width, height = img.size
p_width, p_height =cutImgCopy.size
for left in range(0, width, p_width):
    for top in range(0, height, p_height):
        img.paste(cutImgCopy, (left, top))

img.save('img/p.png')