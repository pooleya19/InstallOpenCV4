#include <iostream>
#include <opencv2/opencv.hpp> // If VSCode has include path error, CTRL+SHIFT+P > Edit Configurations UI > To include path, add "/usr/local/include/opencv4"

using namespace std;
using namespace cv;

// Define index of video source to open
const int videoCaptureIndex = 0;

int main(){
    // Open video capture
    VideoCapture cap(videoCaptureIndex);
    if(cap.isOpened()){
        cout << "Opened camera." << endl;
    }else{
        cout << "Failed to open camera." << endl;
        return 0;
    }

    // Create variable to store frame in
    Mat frame;

    while(true){
        // Get current frame from video capture
        cap >> frame;

        // Display current frame
        imshow("VideoCapture Output (Press Any Key to Quit)", frame);

        // Call waitKey to update windows
        int keyCode = waitKey(1);

        // If key was pressed (!= -1), quit program
        if(keyCode != -1){
            cout << "Key pressed, quitting program..." << endl;
            return 0;
        }
    }
}