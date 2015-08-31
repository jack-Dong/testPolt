// Matlab style plot functions for OpenCV
//author libing64 && Jack Dong
//https://github.com/libing64/CPlot
//
#include "cv.h"
#include "highgui.h"
#include "plot.h"
#include<iostream>

int main(int argc, char* argv[])
{
	const int Cnt = 80;
	double X[Cnt] = {0};
	double Y[Cnt] = {0};
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)i - 20;
	}
	
	cvNamedWindow("hello",1);
	CPlot plot;
	plot.x_max = 100; //可以设定横纵坐标的最大，最小值
	plot.x_min = -20;
	plot.y_max = 400;
	plot.y_min = -200;
	plot.axis_color = Scalar(0,255,0);
	plot.text_color = Scalar(255,0,255);
	plot.plot(Y, Cnt, CV_RGB(0, 0, 0)); //可以只传入Y值 X默认从0开始 
	plot.title("this is a title"); //可以设定标题 只能是英文 中文会乱码 有解决方案，但是很麻烦
	plot.xlabel("this X",Scalar(255,255,0));
	plot.ylabel("this Y",Scalar(255,255,0));
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);

	imwrite("1.jpg",Mat(plot.Figure));

	//如何在一幅图中绘制多组数据？每次绘制的同时还对数据进行存储？
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(5*i - 20);
	}
	plot.plot(X, Y, Cnt, CV_RGB(0, 255, 180), '.',false);//依次传入的参数是 X轴数据； Y轴数据； 数据长度； 线条颜色；点描绘类型（默认是'*'）；点与点之间是否需要连接（默认连接） 
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(-5*i - 20);
	}
	plot.plot(X, Y, Cnt, CV_RGB(0,255, 0), 's');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	imwrite("2.jpg",Mat(plot.Figure));
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(50*sin(i*0.1));
	}
	plot.plot(X, Y, Cnt, CV_RGB(0, 0, 255), 'x');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);

	imwrite("3.jpg",Mat(plot.Figure));



	plot.clear();//清出前面的存储的数据





	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(100*sin(i*0.1));
	}

	plot.plot(X, Y, Cnt, CV_RGB(255, 255, 0), 'o',false);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);

	imwrite("4.jpg",Mat(plot.Figure));

	int X2[Cnt] = {0};
	int Y2[Cnt] = {0};
	for(int i = 0; i < Cnt; i++)
	{
		X2[i] = i;
		Y2[i] = -30*i - 20;
	}
	plot.plot(X2, Y2, Cnt/2, CV_RGB(0, 255, 255),'*',false); //默认会把点与点之间连接在一起
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	//cvSaveImage("example.jpg", plot.Figure);
	imwrite("4.jpg",Mat(plot.Figure));

	//C++ 扩展
	Plot p;
	vector<Point2f> points;
	vector<int> Y_points;
	Point2f p_temp;
	for(int i = 0; i < Cnt; i++)
	{
		p_temp.x = i;
		p_temp.y= -10*i - 20;
		points.push_back(p_temp);
		Y_points.push_back(i * 5 + 1);
	}
	p.plot(Y_points,Scalar(255,255,0));
	imshow("hi",p.figure());
	waitKey();
	p.plot(points,Scalar(255,0,0),'+',false);
	imshow("hi",p.figure());
	waitKey();

	return 0;
}

