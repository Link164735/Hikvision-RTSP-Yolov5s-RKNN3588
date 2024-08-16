import cv2



# RTSP URL

rtsp_url = 'rtsp://admin:xxx@xxx.xxx.xx.xx:xxx/Streaming/Channels/101' #change



# Create a VideoCapture object

cap = cv2.VideoCapture(rtsp_url)



if not cap.isOpened():

    print("Error: Could not open video stream")

else:

    print("Successfully opened video stream")



# Loop to continuously get frames

while True:

    # Capture frame-by-frame

    ret, frame = cap.read()



    # If the frame was not retrieved successfully

    if not ret:

        print("Error: Could not read frame")

        break



    # Display the resulting frame

    cv2.imshow('RTSP Stream', frame)



    # Press 'q' on the keyboard to exit the loop

    if cv2.waitKey(1) & 0xFF == ord('q'):

        break



# When everything is done, release the VideoCapture object

cap.release()



# Close all OpenCV windows

cv2.destroyAllWindows()
