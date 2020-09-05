import cv2
import matplotlib.pyplot as plt
import numpy as np
import math


img= cv2.imread('lenna.png',0)
#img=cv2.resize(img,(512,512))
# fig=plt.figure(figsize=(15,15))
# ax=fig.add_subplot(111)
plt.imshow(img,'gray')
# print(img)


padded_arr =cv2.copyMakeBorder(img,2,2,2,2,cv2.BORDER_CONSTANT,value=0)


kernel=np.array([[1,4,6,4,1],
                [4,16,24,16,4],
                [6,24,36,24,6],
                [4,16,24,16,4],
                [1,4,6,4,1]])

kernel_total=np.sum(kernel)
print(kernel_total)


avg_img=np.zeros(img.shape)
for i in range (img.shape[0]):
    for j in range(img.shape[1]):
        avg_img[i][j]=int(np.sum(padded_arr[i:i+5 , j:j+5]*kernel)/kernel_total)

plt.imshow(avg_img,'gray')
# print(avg_img)



padded_arr_1 =cv2.copyMakeBorder(avg_img,1,1,1,1,cv2.BORDER_CONSTANT,value=0)
# print(padded_arr_1)



sobel_x=np.array([[-1,0,1],[-2,0,2],[-1,0,1]])
sobel_y=np.array([[1,2,1],[0,0,0],[-1,-2,-1]])

real_img=np.zeros(img.shape,'uint8')

sobel_x_img=np.zeros(img.shape)
sobel_y_img=np.zeros(img.shape)

for i in range (img.shape[0]):
    for j in range(img.shape[1]):
        sx=np.sum(padded_arr_1[i:i+3,j:j+3]*sobel_x)
        sy=np.sum(padded_arr_1[i:i+3,j:j+3]*sobel_y)
        real_img[i][j]=round(math.sqrt(sx*sx + sy*sy))
        sobel_x_img[i,j]=sx
        sobel_y_img[i,j]=sy

# print(sobel_x_img)
plt.imshow(sobel_x_img,'gray')
plt.title("X axis Image")
plt.show()
# print(sobel_y_img)
plt.imshow(sobel_y_img,'gray')
plt.title("Y axis Image")
plt.show()


#print(real_img)
fig=plt.figure(figsize=(5,5))
ax=fig.add_subplot(111)
plt.imshow(real_img,'gray')
plt.title("Sobel Edge Detection")


threshold_value=50
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        if real_img[i][j]<threshold_value:
            real_img[i][j]=0

fig=plt.figure(figsize=(10,10))
ax=fig.add_subplot(111)
plt.imshow(real_img,'gray')
plt.title("Sobel Edge Detection Image")
#print(sobel)
