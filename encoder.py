from PIL import Image
import numpy as np
im = Image.open("spongebob.png")
# im = im.convert('RGB')
pixels = im.load()
print(pixels[0,0])
encoded = "hello".encode("ascii")
print (encoded)
for i in encoded:
    print (bin(i))
# pixels[10,10] = 0
print(bin(encoded[0])+bin(encoded[1]))
# im.load(pixels)
im.save("pixel_grid.png")