/*string data;

int k = 0;
int j = 0;
int o = 0;
ifstream myfile(name);
while (!myfile.eof())
{
	getline(myfile, data);
	o++;
	if (o == 4)
	{
		str = data;
		setwh(str);
	}
	if (o == 6)
	{

		for (int i = 0; data[i] != '\0'; i++)
		{
			if (white + black <= row * col)
			{
				if (j == col)
				{
					j = 0;
					k++;
				}
			}
			if (data[i] == 'ÿ')
			{
				//cout << width << height;
				ptr[k][j] = 255;
				white++;
				j++;
			}
			else if (data[i] == ' ')
			{
				//cout << width << height;
				ptr[k][j] = 0;
				black++;
				j++;
			}

		}

	}
}

myfile.close();

#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int x;
	cv::Mat img = cv::imread("bat-5.pgm", IMREAD_GRAYSCALE);
	for (int i = 0; i < img.rows; i++)//loop for rows//
	{
		for (int j = 0; j < img.cols; j++)//loop for columns//
		{
			x = (int)img.at<uchar>(i, j);//storing value of (i,j) pixel in variable//
	cout << "Value of pixel" << "(" << i << "," << j << ")" << "=" << x << endl;//showing the values in console window//
}
   }
	//cv::Mat image_copy = test_image.clone();
	//namedWindow("Show Image", 1);
	//imshow("Show Image", test_image);
	waitKey(0);
}
*/

//void image::setwh(string str)
//{
//	col = stoi(str);
//	int i = 0;
//	string s;
//	while (str[i] != '\0')
//	{
//		if (str[i] != ' ')
//		{
//			s += str[i];
//		}
//		else
//		{
//			s = "";
//		}
//		i++;
//
//	}
//
//	row = stoi(s);
//
//
//	//	cout << row;
//		//cout << col;
//}








//ofstream myfile;
//myfile.open("example.pgm", ios::trunc);
//myfile << "P5" << endl;
//myfile << "#" << name << endl;
//myfile << "#converted PNM file" << endl;
//myfile << col << " " << row << endl;
//myfile << "255" << endl;
//for (int i = 0; i < row; i++)
//{
//	for (int j = 0; j < col; j++)
//	{
//		if (write2[i][j] == 255)
//		{
//			myfile << "ÿ";
//		}
//		else if (write2[i][j] == 0)
//		{
//			myfile << " ";
//		}
//	}
//}
//cout << "complete" << endl;
//myfile.close();\










//#pragma once
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//#include "Functions.h"
//
//using namespace cv;
//using namespace std;
//
//// Function to display the image.
//void SaveImage(string path, int**& pixels, string& name) {
//	Mat img = imread(path, IMREAD_GRAYSCALE);
//	for (int i = 0; i < img.rows; i++) {
//		for (int j = 0; j < img.cols; j++) {
//			img.at<uchar>(i, j) = pixels[i][j];
//		}
//	}
//	imshow(name + ".jpg", img);
//	//imwrite(name + ".png", img);
//	waitKey(0);
//}
//
//// Function for setting the pixel in the 2d array.
//void Set_Pixels(int**& arr, int& rows, int& cols, Mat image) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			arr[i][j] = int(image.at<uint8_t>(i, j));
//		}
//	}
//}
//
//void makeBlank(int**& blank, int& rows, int& cols) {
//	// Storing all black pixels in the blank image.
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			blank[i][j] = 0;
//		}
//	}
//}
//
//int Separate(string path) {
//	Mat image = imread(path, IMREAD_GRAYSCALE);
//	//imshow("Original Image", image);
//	waitKey(0);
//
//	int** pixels = new int* [image.rows];
//	for (int i = 0; i < image.rows; i++) {
//		pixels[i] = new int[image.cols] {};
//	}
//
//	// Extra Black Image of same size;
//	int** blank = new int* [image.rows];
//	for (int i = 0; i < image.rows; i++) {
//		blank[i] = new int[image.cols] {};
//	}
//	makeBlank(blank, image.rows, image.cols);
//
//	//Storing the value of each pixel in the declared 2d array.
//	Set_Pixels(pixels, image.rows, image.cols, image);
//	int m = 0, n = 0;
//	Queue x;
//	Queue y;
//	int count = 1;
//
//	string name = "Galaxy_0";
//	for (int i = 1; i < (image.rows - 1); i++) {
//		for (int j = 1; j < (image.cols - 1); j++) {
//			if (pixels[i][j] == 255) {
//				x.Enqueue(i), y.Enqueue(j);
//				while ((!x.isEmpty()) && (!y.isEmpty())) {
//					m = x.Dequeue();
//					n = y.Dequeue();
//
//					// TOP-LEFT
//					if (pixels[m - 1][n - 1] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n - 1);
//						pixels[m - 1][n - 1] = 0;
//						blank[m - 1][n - 1] = count;
//					}
//					// TOP
//					if (pixels[m - 1][n] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n);
//						pixels[m - 1][n] = 0;
//						blank[m - 1][n] = count;
//					}
//					// TOP-RIGHT
//					if (pixels[m - 1][n + 1] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n + 1);
//						pixels[m - 1][n + 1] = 0;
//						blank[m - 1][n + 1] = count;
//					}
//					// RIGHT
//					if (pixels[m][n + 1] == 255) {
//						x.Enqueue(m), y.Enqueue(n + 1);
//						pixels[m][n + 1] = 0;
//						blank[m][n + 1] = count;
//					}
//					// BOTTOM-RIGHT
//					if (pixels[m + 1][n + 1] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n + 1);
//						pixels[m + 1][n + 1] = 0;
//						blank[m + 1][n + 1] = count;
//					}
//					// BOTTOM
//					if (pixels[m + 1][n] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n);
//						pixels[m + 1][n] = 0;
//						blank[m + 1][n] = count;
//					}
//					// BOTTOM-LEFT
//					if (pixels[m + 1][n - 1] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n - 1);
//						pixels[m + 1][n - 1] = 0;
//						blank[m + 1][n - 1] = count;
//					}
//					// LEFT
//					if (pixels[m][n - 1] == 255) {
//						x.Enqueue(m), y.Enqueue(n - 1);
//						pixels[m][n - 1] = 0;
//						blank[m][n - 1] = count;
//					}
//				}
//				count++;
//
//			}
//		}
//	}
//
//	// Declaring a array of max size.
//	int* reps = new int[count - 1] {};
//
//	// Finding max occurrence of each label.
//	for (int i = 0; i < count - 1; i++) {
//		for (int j = 0; j < image.rows; j++) {
//			for (int k = 0; k < image.cols; k++) {
//				if (blank[j][k] == i + 1)
//					reps[i]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < count - 1; i++) {
//		cout << reps[i] << "    ";
//	}
//
//
//	int p = 0;
//	int index = 0;
//
//	// Finding the index of most repeated label.
//	for (int i = 0; i < count - 1; i++) {
//		if (p < reps[i]) {
//			p = reps[i];
//			index = i + 1;
//		}
//	}
//
//	cout << endl << endl << index << endl << endl;
//
//	// Labelling other labels as zeros.
//	for (int i = 1; i < (image.rows - 1); i++) {
//		for (int j = 1; j < (image.cols - 1); j++) {
//			if (blank[i][j] == index) {
//				blank[i][j] = 255;
//			}
//
//			else
//				blank[i][j] = 0;
//		}
//	}
//
//
//
//	string str = "galaxy";
//	SaveImage(path, blank, str);
//
//	return count;
//}
//
//
//
//




//


//// Function to display the image.
//void image::SaveImage(string path, int**& pixels, string name) {
//	Mat img = imread(path, IMREAD_GRAYSCALE);
//	for (int i = 0; i < img.rows; i++) {
//		for (int j = 0; j < img.cols; j++) {
//			
//			if (pixels[i][j]==0 )
//			{
//				img.at<uchar>(i, j) =' ';
//			}
//			else if (pixels[i][j] == 255)
//			{
//				img.at<uchar>(i, j) = 255;
//			}
//		}
//	}
//		
//	
//	imshow(name , img);
//	imwrite("example.pgm", img);
//	waitKey(0);
//}
//
//void image::Set_Pixels(int**& arr, int& rows, int& cols, Mat image) {
//	int x;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			x= int(image.at<uint8_t>(i, j));
//			if (x == 0 || x==32)		
//			{
//				arr[i][j] = 0;
//			}
//			else if(x==255)
//			{
//				arr[i][j] = 255;
//			}
//		}
//	}
//
//	
//}
//for (int i = 1; i < (rows - 1); i++) {
//	for (int j = 1; j < (cols - 1); j++) {
//
//		cout << blank[i][j];
//
//	}
//}
//for (int i = 1; i < (rows - 1); i++) {
//	for (int j = 1; j < (cols - 1); j++) {
//
//		blank[i][j] = pixels[i][j];
//
//	}
//}




//oid image::check(string path) {
//
//	Mat image = imread(path, IMREAD_GRAYSCALE);
//
//	int** pixels = new int* [image.rows];
//	for (int i = 0; i < image.rows; i++) {
//		pixels[i] = new int[image.cols] {};
//	}
//	Set_Pixels(pixels, image.rows, image.cols, image);
//	ptr = pixels;
//
//	row = image.rows;
//	col = image.cols;
//	int rows = image.rows;
//	int cols = image.cols;
//	//for (int i = 1; i < (rows - 1); i++) {
////	for (int j = 1; j < (cols - 1); j++) {
////
////		cout << pixels[i][j];
////
////	}
////}	
//
//	// Extra Black Image of same size;
//	int** blank = new int* [rows];
//	for (int i = 0; i < rows; i++) {
//		blank[i] = new int[cols] {};
//	}
//
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < cols; j++)
//			blank[i][j] = 0;
//
//	int m = 0, n = 0;
//	Queue x;
//	Queue y;
//	int count = 1;
//
//	for (int i = 1; i < (rows - 1); i++) {
//		for (int j = 1; j < (cols - 1); j++) {
//			if (pixels[i][j] == 255) {
//				x.Enqueue(i), y.Enqueue(j);
//				while ((!x.isEmpty()) && (!y.isEmpty())) {
//					m = x.Dequeue();
//					n = y.Dequeue();
//
//					// TOP-LEFT
//					if (pixels[m - 1][n - 1] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n - 1);
//						pixels[m - 1][n - 1] = 0;
//						blank[m - 1][n - 1] = count;
//					}
//					// TOP
//					if (pixels[m - 1][n] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n);
//						pixels[m - 1][n] = 0;
//						blank[m - 1][n] = count;
//					}
//					// TOP-RIGHT
//					if (pixels[m - 1][n + 1] == 255) {
//						x.Enqueue(m - 1), y.Enqueue(n + 1);
//						pixels[m - 1][n + 1] = 0;
//						blank[m - 1][n + 1] = count;
//					}
//					// RIGHT
//					if (pixels[m][n + 1] == 255) {
//						x.Enqueue(m), y.Enqueue(n + 1);
//						pixels[m][n + 1] = 0;
//						blank[m][n + 1] = count;
//					}
//					// BOTTOM-RIGHT
//					if (pixels[m + 1][n + 1] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n + 1);
//						pixels[m + 1][n + 1] = 0;
//						blank[m + 1][n + 1] = count;
//					}
//					// BOTTOM
//					if (pixels[m + 1][n] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n);
//						pixels[m + 1][n] = 0;
//						blank[m + 1][n] = count;
//					}
//					// BOTTOM-LEFT
//					if (pixels[m + 1][n - 1] == 255) {
//						x.Enqueue(m + 1), y.Enqueue(n - 1);
//						pixels[m + 1][n - 1] = 0;
//						blank[m + 1][n - 1] = count;
//					}
//					// LEFT
//					if (pixels[m][n - 1] == 255) {
//						x.Enqueue(m), y.Enqueue(n - 1);
//						pixels[m][n - 1] = 0;
//						blank[m][n - 1] = count;
//					}
//				}
//				count++;
//
//			}
//		}
//	}
//
//	// Declaring a array of max size.
//	int* reps = new int[count - 1] {};
//
//	// Finding max occurrence of each label.
//	for (int i = 0; i < count - 1; i++) {
//		for (int j = 0; j < rows; j++) {
//			for (int k = 0; k < cols; k++) {
//				if (blank[j][k] == i + 1)
//					reps[i]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < count - 1; i++) {
//		cout << reps[i] << "    ";
//	}
//
//
//	int p = 0;
//	int index = 0;
//
//	// Finding the index of most repeated label.
//	for (int i = 0; i < count - 1; i++) {
//		if (p < reps[i]) {
//			p = reps[i];
//			index = i + 1;
//			//cout << p;
//
//		}
//	}
//
//	cout << endl << endl << index << endl << endl;
//
//	// Labelling other labels as zeros.
//	for (int i = 1; i < (rows - 1); i++) {
//		for (int j = 1; j < (cols - 1); j++) {
//			if (blank[i][j] == index) {
//				blank[i][j] = 255;
//			}
//
//			else
//				blank[i][j] = 0;
//		}
//
//	}
//	string str = "galaxy";
//	SaveImage(path, blank, str);
//}
//





///queue
	// Function to search through dequeing and enqueing.
//bool search(int data) {
//	int count = 0;
//	int n = 0;
//	for (int i = 0; i < No_of_Nodes(); i++) {
//		if ((n = Dequeue()) != data) {
//			Enqueue(n);
//			count++;
//		}
//		else {
//			int m = No_of_Nodes() - count;
//			if (count == 0)
//				m = 0;
//
//			for (int i = 0; i < m; i++) {
//				n = Dequeue();
//				Enqueue(n);
//			}
//			return true;
//		}
//	}
//	return false;
//}
//
//// Getters
//nodes* Getfront() {
//	return this->front;
//}
//
//nodes* Getrear() {
//	return this->rear;
//}
//
//
//// For printing all the values of the node.
//void Traverse() {
//	nodes* trav = front;
//
//	cout << "\n\n";
//	while (trav != NULL) {
//		cout << "|" << trav->data << "| -> ";
//		trav = trav->next;
//	}
//	cout << "|NULL|" << endl;
//	cout << "\n\n";
//}
//
//
//int No_of_Nodes() {
//	nodes* trav = front;
//	int count = 0;
//
//	while (trav != NULL) {
//		count++;
//		trav = trav->next;
//	}
//	return count;
//}
//
//// To get the data of front node.
//int Front() {
//	return front->data;
//}
//
//int Rear() {
//	return rear->data;
//}











//
//////////////////////////////////////////////////////////////////////   Node   ////////////////////////////////////////////////////////////////////////////////
//struct node {
//	node* next;
//	int data;
//
//	// Parametrized Constructor
//	node(int data = 0) {
//		this->next = NULL;
//		this->data = data;
//	}
//};
//
//
//////////////////////////////////////////////////////////////////////   STACK   /////////////////////////////////////////////////////////////////////////////
//
//void image::checks(int** pixels)
//{
//	// Extra Black Image of same size;
//	int** blank = new int* [row];
//	for (int i = 0; i < row; i++) {
//		blank[i] = new int[col] {};
//	}
//
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < col; j++)
//			blank[i][j] = 0;
//
//	int m = 0, n = 0;
//	Stack x;
//	Stack y;
//	int count = 1;
//
//	for (int i = 1; i < (col - 1); i++) {
//		for (int j = 1; j < (row - 1); j++) {
//			if (pixels[i][j] == 255) {
//				x.push(i), y.push(j);
//				while ((!x.isempty()) && (!y.isempty())) {
//					m = x.pop();
//					n = y.pop();
//
//					// TOP-LEFT
//					if (pixels[m - 1][n - 1] == 255) {
//						x.push(m - 1), y.push(n - 1);
//						pixels[m - 1][n - 1] = 0;
//						blank[m - 1][n - 1] = count;
//					}
//					// TOP
//					if (pixels[m - 1][n] == 255) {
//						x.push(m - 1), y.push(n);
//						pixels[m - 1][n] = 0;
//						blank[m - 1][n] = count;
//					}
//					// TOP-RIGHT
//					if (pixels[m - 1][n + 1] == 255) {
//						x.push(m - 1), y.push(n + 1);
//						pixels[m - 1][n + 1] = 0;
//						blank[m - 1][n + 1] = count;
//					}
//					// RIGHT
//					if (pixels[m][n + 1] == 255) {
//						x.push(m), y.push(n + 1);
//						pixels[m][n + 1] = 0;
//						blank[m][n + 1] = count;
//					}
//					// BOTTOM-RIGHT
//					if (pixels[m + 1][n + 1] == 255) {
//						x.push(m + 1), y.push(n + 1);
//						pixels[m + 1][n + 1] = 0;
//						blank[m + 1][n + 1] = count;
//					}
//					// BOTTOM
//					if (pixels[m + 1][n] == 255) {
//						x.push(m + 1), y.push(n);
//						pixels[m + 1][n] = 0;
//						blank[m + 1][n] = count;
//					}
//					// BOTTOM-LEFT
//					if (pixels[m + 1][n - 1] == 255) {
//						x.push(m + 1), y.push(n - 1);
//						pixels[m + 1][n - 1] = 0;
//						blank[m + 1][n - 1] = count;
//					}
//					// LEFT
//					if (pixels[m][n - 1] == 255) {
//						x.push(m), y.push(n - 1);
//						pixels[m][n - 1] = 0;
//						blank[m][n - 1] = count;
//					}
//				}
//				count++;
//
//			}
//		}
//	}
//
//	// Declaring a array of max size.
//	int* reps = new int[count - 1] {};
//
//	// Finding max occurrence of each label.
//	for (int i = 0; i < count - 1; i++) {
//		for (int j = 0; j < row; j++) {
//			for (int k = 0; k < col; k++) {
//				if (blank[j][k] == i + 1)
//					reps[i]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < count - 1; i++) {
//		cout << reps[i] << "    ";
//	}
//
//
//	int p = 0;
//	int index = 1;
//
//	// Finding the index of most repeated label.
//	for (int i = 0; i < count - 1; i++) {
//		if (p < reps[i]) {
//			p = reps[i];
//			index = i + 1;
//			//cout << p;
//
//		}
//	}
//
//	cout << endl << endl << index << endl << endl;
//
//	// Labelling other labels as zeros.
//	for (int i = 1; i < (row - 1); i++) {
//		for (int j = 1; j < (col - 1); j++) {
//			if (blank[i][j] == index) {
//				blank[i][j] = 255;
//			}
//
//			else
//				blank[i][j] = 0;
//		}
//
//	}
//	iwrite = blank;
//}