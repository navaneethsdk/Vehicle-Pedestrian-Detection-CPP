#pragma once
#ifndef VEH_DET
#define VEH_DET

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void detectCars(Mat img, CascadeClassifier carCascade);
void detectPedestrians(Mat img, CascadeClassifier pedCascade);
void detectBikes(Mat img, CascadeClassifier bikeCascade);

#endif