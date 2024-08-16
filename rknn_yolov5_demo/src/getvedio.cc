#include <opencv2/opencv.hpp>

#include <iostream>



int main() {

    // RTSP URL

    std::string rtsp_url = "rtsp://admin:xxx@xxx.xxx.xx.xx:xxx/Streaming/Channels/101";//change



    // Create a VideoCapture object

    cv::VideoCapture cap(rtsp_url);



    if (!cap.isOpened()) {

        std::cerr << "Error: Could not open video stream" << std::endl;

        return -1;

    } else {

        std::cout << "Successfully opened video stream" << std::endl;

    }



    // Loop to continuously get frames

    while (true) {

        // Capture frame-by-frame

        cv::Mat frame;

        bool ret = cap.read(frame);



        // If the frame was not retrieved successfully

        if (!ret) {

            std::cerr << "Error: Could not read frame" << std::endl;

            break;

        }



        // Display the resulting frame

        cv::imshow("RTSP Stream", frame);



        // Press 'q' on the keyboard to exit the loop

        if (cv::waitKey(1) == 'q') {

            break;

        }

    }



    // When everything is done, release the VideoCapture object

    cap.release();



    // Close all OpenCV windows

    cv::destroyAllWindows();



    return 0;

}
