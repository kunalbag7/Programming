import cv2
import numpy as np

face_classifire = cv2.CascadeClassifier('C:\\Users\\user\\Anaconda3\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_default.xml')

def face_extractor (img):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    face = face_classifire.detectMultiScale(gray,1.3,5)

    if face is ():
        return None

    for (x,y,w,h) in face:
        crop_face= img[y:y+h , x:x+w]

    return crop_face

vid= cv2.VideoCapture(0)
count=0
while True:
    ref, frame = vid.read()
    if face_extractor(frame) is not None:
        count +=1
        face = cv2.resize(face_extractor(frame), (200,200))
        face= cv2.cvtColor(face, cv2.COLOR_BGR2GRAY)

        file_name_path = 'C:\\Users\\user\\Pictures\\bonka\\BONKA' + str(count) + '.jpg'
        cv2.imwrite(file_name_path, face)

        cv2.putText(face,str(count),(50,50),cv2.FONT_HERSHEY_COMPLEX,1,(0,255,0),2)
        cv2.imshow('Cropped Faces',face)

    else:
        print('Face not found.')
        pass

    if(cv2.waitKey(1)== 13 or count == 150):
        break

vid.release()
cv2.destroyAllWindows()
print('Collection samples complete !!')




