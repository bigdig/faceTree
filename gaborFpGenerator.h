#ifndef GABOR_FP_GENERATOR_H
#define GABOR_FP_GENERATOR_H

#include <cv.h>
#include "histogram.hpp"
#include "cvgabor.h"

using namespace cv;
using namespace std;

namespace gaborFp{
	class GaborFp{
	private:
		Mat srcImage;
		const static double Sigma;
		const static double F;
		vector<Mat> gaborImageList;

		void getGaborImage(int thetaIndex,int scale, Mat& outPut);	//���ָ��theta��scale��gabor�˲���������ͼ��
		void getGaborImageList();	//���ȫ��gabor�˲����˲����ͼ������0~8*PI/8,8����0~5,5��scale
		void downSampleGaborImage(Mat &gaborImage);	//rou=32����������128*128ͼ����4*4=16ά��������������16*40=640ά��
	public:
		GaborFp(Mat image):srcImage(image) { getGaborImageList(); }
		~GaborFp() {
			srcImage.release();
			for ( vector<Mat>::iterator it = gaborImageList.begin(); it != gaborImageList.end(); ++it ){
				it->release();
			}
			gaborImageList.clear();
		}

		Mat getGaborFp();	//���Gabor����������Ϊ8����5�߶ȵ�40��gabor�˲���ͼ��ƴ�ӳ�һ����������Ϊ����
	};

	const double Sigma = 2*PI;
	const double F = sqrt(2.0);
	Mat getFpHistogram(const Mat& src);
}

#endif