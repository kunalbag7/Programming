import cv2
import numpy as np

hand= cv2.imread('C:\\Users\\user\\Pictures\\hand.jpg',0)

ret, ths = cv2.threshold(hand, 70, 255, cv2.THRESH_BINARY)

_,con,_ = cv2.findContours(ths.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

hull= [cv2.convexHull(c) for c in con ]

final= cv2.drawContours(hand, hull, -1, (255,0,0))

cv2.imshow('Original',hand)

cv2.imshow('Thershold',ths)

cv2.imshow('Convex',final)

cv2.waitKey(0)

cv2.destroyAllWindows()