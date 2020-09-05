import cv2

face_classifire = cv2.CascadeClassifier('C:\\Users\\user\\Anaconda3\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_default.xml')

def face_extractor (img):
    gray= cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    face= face_classifire.detectMultiScale(gray,1.3,5)

    if face is ():
        return None

    for (x,y,w,h) in face:
        crop_face= img[y:y+h , x:x+w]
        crop_face=cv2.cvtColor(crop_face,cv2.COLOR_BGR2GRAY)
        cv2.imwrite('C:\\Users\\user\\Pictures\\newface\\new' + str(w) + str(h) + '.jpg' , crop_face)


i=cv2.imread('C:\\Users\\user\\Pictures\\test.jpg')

face_extractor(i)






