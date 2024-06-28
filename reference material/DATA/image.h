#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include<list>
using namespace cv;
using namespace std;

class image
{public:
	int black;
	int white;
	string str;
	int** ptr;
	int** iwrite;
	int row;
	int col;
	string name;
	string str2;
	string pgmpath;

	void npixels();
	int ablack();
	image();
	int meanpixel();
	int ** read(string name,int c);
	void display();
	//void setwh(string str);
	void write(int**& write2);
	//void check(string path);
	void  check(int** pixels, int c);
	void checks(int** pixels, int c);
	void Set_Pixels(int**& arr, int& rows, int& cols, Mat image);
	int getpixel(int r, int c);
	int setpixel(int pixel, int r, int c);
	int getsize();
	void convert();
	void SaveImage(string path, int**& pixels, string name);
	void rlcencode();
	void rlcdecode();
	void hashdatabase();
};

