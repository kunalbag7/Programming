import cv2
import matplotlib.pyplot as plt
import numpy as np
import math


img= cv2.imread('img2.png',0)
# img=cv2.resize(img,(512,512))
# fig=plt.figure(figsize=(15,15))
# ax=fig.add_subplot(111)
plt.imshow(img,'gray')
print(img)


padded_arr =cv2.copyMakeBorder(img,1,1,1,1,cv2.BORDER_CONSTANT,value=0)
new_img=np.zeros(img.shape)


for i in range (img.shape[0]):
    for j in range(img.shape[1]):
        median=np.zeros((3,3))
        median=padded_arr[i:i+3 , j:j+3]
        np.reshape(median,9, order='F')
        new_img[i][j]=np.median(median)
        
        
#print(mediang)


plt.imshow(new_img,'gray')



