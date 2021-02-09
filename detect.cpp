#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include "Header Files/Detection.hpp"
using namespace cv;
using namespace std;


/////////////////  Vehicle detection  //////////////////////

void detectCars(Mat img, CascadeClassifier carCascade) {
    Mat imgGray;
    String car = "car";
    vector<Rect> cars;
    

    if (carCascade.empty()) {
        cout << "Car XML file not loaded";
    }
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    carCascade.detectMultiScale(imgGray, cars, 1.1, 7);

    for (int i = 0; i < cars.size(); i++)
    {
        putText(img, car, {cars[i].tl().x,cars[i].tl().y}, FONT_HERSHEY_COMPLEX, 0.75, Scalar(255, 0,255), 2);
        rectangle(img, cars[i].tl(), cars[i].br(), Scalar(255, 0, 255), 3); 
    }

    imshow("Image", img);

}

void detectPedestrians(Mat img, CascadeClassifier pedCascade) {
    Mat imgGray;
    String Ped = "Pedestrian";
    vector<Rect>  pedestrians;
    

    if (pedCascade.empty()) {
        cout << "Pedestrian XML file not loaded";
    }
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    pedCascade.detectMultiScale(imgGray, pedestrians, 1.3, 2);

    for (int i = 0; i < pedestrians.size(); i++)
    {
        putText(img, Ped, {pedestrians[i].tl().x,pedestrians[i].tl().y}, FONT_HERSHEY_COMPLEX, 0.5, Scalar(255, 0,0), 2);
        rectangle(img, pedestrians[i].tl(), pedestrians[i].br(), Scalar(255, 0, 0), 3); 
    }

    imshow("Image", img);

}

void detectBikes(Mat img, CascadeClassifier bikeCascade) {
    Mat imgGray;
    String bike = "Bikes";
    vector<Rect>  bikes;
    

    if (bikeCascade.empty()) {
        cout << "Bike XML file not loaded";
    }
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    bikeCascade.detectMultiScale(imgGray, bikes,1.19, 1);

    for (int i = 0; i < bikes.size(); i++)
    {
        putText(img, bike, {bikes[i].tl().x,bikes[i].tl().y}, FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255,0), 2);
        rectangle(img, bikes[i].tl(), bikes[i].br(), Scalar(0, 255, 0), 3); 
    }

    imshow("Image", img);

}