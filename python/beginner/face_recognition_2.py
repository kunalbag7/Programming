import cv2 as cv
import numpy as np
from os import listdir
from os.path import isfile, join

path='C:\\Users\\user\\Pictures\\bonka\\'

files= [ f for f in listdir(path)  if isfile(join(path,f))]

training_data , Labels = [],[]
for i , file in enumerate(files):
    image_path = path + files[i]
    images = cv.imread(image_path,cv.IMREAD_GRAYSCALE)
    training_data.append(np.asarray(images , dtype=np.uint8))
    Labels.append(i)

Labels=np.asarray(Labels, dtype=np.int32)

model = cv.face.LBPHFaceRecognizer_create()
model.train(np.asarray(training_data), np.asarray(Labels))

print('Model trained Successfully !!')

face_classifire = cv.CascadeClassifier('C:\\Users\\user\\Anaconda3\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_default.xml')

def face_detector(img, size=0.5):
    gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    faces = face_classifire.detectMultiScale(gray,1.3,5)

    if faces is ():
        return img,[]
    for (x,y,w,h) in faces:
        cv.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        roi = img[ y:y+h,x:x+w]
        roi= cv.resize(roi, (200,200))
        return  img, roi

cap=cv.VideoCapture(0)
while True:
    ret, frame = cap.read()
    image , face = face_detector(frame)

    try:
        face = cv.cvtColor(face,cv.COLOR_BGR2GRAY)
        result = model.predict(face)
        if result[1] < 500 :
            confidence = int(100*(1-(result[1]/300)))
            display = str(confidence)+'% Sure that you are RAJDEEP'
        cv.putText(image,display,(100,100),cv.FONT_ITALIC,1,(255,1,0),2)

        if confidence > 75:
            #cv.putText(image, 'Kunal' , (250,450), cv.FONT_HERSHEY_DUPLEX, 1, (255, 0 , 240), 2)
            cv.imshow('Face Recognisation',image)
        else:
            #cv.putText(image, 'Unknown', (250, 450), cv.FONT_HERSHEY_DUPLEX, 1, (255, 240, 0), 2)
            cv.imshow('Face Recognisation', image)

    except:
        cv.putText(image, 'Face Not Found', (250, 450), cv.FONT_HERSHEY_COMPLEX, 1, (255, 100, 240), 2)
        cv.imshow('Face Recognisation', image)
        pass

    if cv.waitKey(1)== 13:
        break

cap.release()
cv.destroyAllWindows()




