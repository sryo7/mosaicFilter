// mosaic2.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

void mosaic(int size);

Mat src;
cv::Mat dat;

int main()
{
	src = imread("img/arimura.png");

	int size = 1;
	namedWindow("mosaicchanger", 1);
	createTrackbar("Move it", "mosaicchanger", &size, 100);

	while (1) {
		mosaic(size);
		namedWindow("result", 1);
		imshow("result", dat);

		int iKey = waitKey(50);
		if (iKey > 0) { break; }
	}

		//namedWindow("result", 1);
		//imshow("result", dat);
		//waitKey(0);

    return 0;
}

void mosaic(int size) {
	dat = src.clone();

	for (int y = 0;y*size+size-1< src.rows; y++) {
		for (int x = 0; x*size + size - 1< src.cols; x++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					dat.at<Vec3b>(size * y + i, size * x + j) = src.at<Vec3b>(size * y, size * x);
					
				}
			}
			
		}
	}

}
