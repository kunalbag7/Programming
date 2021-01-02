import cv2

license_plate = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
# Read the input image
#img = cv2.imread('test.png')
cap = cv2.VideoCapture('test.mp4')
# Check if camera opened successfully
# if (cap.isOpened()== False): 
#   print("Error opening video stream or file")

# # Read until video is completed
# while(cap.isOpened()):
#   # Capture frame-by-frame
#   ret, frame = cap.read()
#   if ret == True:

#     # Display the resulting frame
#     cv2.imshow('Frame',frame)

#     # Press Q on keyboard to  exit
#     if cv2.waitKey(25) & 0xFF == ord('q'):
#       break

#   # Break the loop
#   else: 
#     break

# # When everything done, release the video capture object
# cap.release()

while cap.isOpened():
    _, img = cap.read()

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    plate =license_plate.detectMultiScale(gray, 1.1, 5,flags=cv2.CASCADE_SCALE_IMAGE)

    for (x, y , w ,h) in plate:
        cv2.rectangle(img, (x,y), (x+w, y+h), (255, 0 , 0), 3)

    # Display the output
    cv2.imshow('img', img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

# Closes all the frames
cv2.destroyAllWindows()