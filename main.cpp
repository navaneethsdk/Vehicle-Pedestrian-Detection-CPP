#include <iostream>
#include <opencv2/objdetect.hpp>
#include "Header Files/Detection.hpp"
using namespace std;


int main() {
    CascadeClassifier carCascade, pedCascade, bikeCascade;
    carCascade.load("Resources/cars.xml");
    pedCascade.load("Resources/pedestrian.xml");
    bikeCascade.load("Resources/two_wheeler.xml");
    string path = "Resources/test2.mp4";
    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap(path); 
    
    // Check if camera opened successfully
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
        
    while(1){

        Mat frame;
        // Capture frame-by-frame
        cap >> frame;
    
        // If the frame is empty, break immediately
        if (frame.empty())
        break;

        // Detect cars
        detectCars(frame, carCascade);
        detectPedestrians(frame, pedCascade);
        detectBikes(frame, bikeCascade);

        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        if(c==27)
        break;
    }
    
    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();
    
    return 0;
}