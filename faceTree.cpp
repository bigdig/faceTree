// faceTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>

#include "lbp.hpp"
#include "histogram.hpp"
#include "lbpFpGenerator.h"

#include <io.h>
#include <fstream>
#include "fpRecorder.h"
#include "cvgabor.h"
#include "gaborFpGenerator.h"
#include "fpGrouper.h"
#include "global.h"
//#include <vld.h>	//����ڴ�й¶

using namespace std;
using namespace cv;

int getFileLocList( const string& dir, vector<string>& fileLocList );

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"hello world"<<endl;
	string imageLoc = "H:/pic/lena.jpg";
	/*Mat image = imread(imageLoc);
	imshow("test",image);
	waitKey();*/

	//////////////////////////////////////////////////
	////	����lbp������Ԫ����
	//Mat lbpFpHist = lbpFp::getFpHistogram(image,256);
	//string loc = "D:/test.txt";
	//fpRecorder::writeToText(lbpFpHist,loc);

	//////////////////////////////////////////////////////
	////	��ȡ������ȫ��ͼƬ��lbp������lbpFpList.txt
	//string srcDir = "E:/360/face/face_urls/";
	//vector<string> imageList;
	//getFileLocList(srcDir,imageList);

	//string lbpFpListLoc = "D:/lbpFpList.txt";
	//for ( vector<string>::iterator it = imageList.begin(); it !=imageList.end(); ++it){
	//	Mat image = imread(*it);
	//	Mat lbpFpHist = lbpFp::getFpHistogram(image,256);
	//	fpRecorder::writeToText(lbpFpHist,lbpFpListLoc);
	//}

	/////////////////////////////////////////////////////////////
	////	Gabor������Ԫ����
	////����һ��������PI/4���߶���3��gabor
	//double Sigma = 2*PI;
	//double F = sqrt(2.0);
	//CvGabor *gabor1 = new CvGabor; 
	//gabor1->Init(PI/2, 4, Sigma, F); 
	////���ʵ������ʾ��
	//IplImage *kernel = cvCreateImage( cvSize(gabor1->get_mask_width(), gabor1->get_mask_width()), IPL_DEPTH_8U, 1);  
	//kernel = gabor1->get_image(CV_GABOR_REAL);  
	//cvNamedWindow("Gabor Kernel", 1);  
	//cvShowImage("Gabor Kernel", kernel);  
	//cvWaitKey(0);
	////����ͼƬ����ʾ
	//Mat img;
	//cvtColor(image, img, CV_BGR2GRAY);
	//imshow("grayImage",img);
	//waitKey(0);
	////��ȡ����ͼ���gabor�˲���Ӧ��ʵ��������ʾ
	//IplImage *reimg = cvCreateImage(cvSize(img.cols,img.rows), IPL_DEPTH_8U, 1);  
	//gabor1->conv_img(&IplImage(img), reimg, CV_GABOR_REAL);  
	//cvNamedWindow("Real Response", 1);  
	//cvShowImage("Real Response",reimg);  
	//cvWaitKey(0);  
	//cvDestroyWindow("Real Response");
	////��ȡ����ͼ���gabor�˲���Ӧ��ģ������ʾ
	//IplImage *magimg = cvCreateImage(cvSize(img.cols,img.rows), IPL_DEPTH_8U, 1);  
	//gabor1->conv_img(&IplImage(img), reimg, CV_GABOR_MAG);  
	//cvNamedWindow("Magnitude Response", 1);  
	//cvShowImage("Magnitude Response",reimg);
	//cvWaitKey(0);
	////�����Ӧ���Ա�ȡ��Ϊ8λ�ĻҶ�ͼ�������Ҫԭʼ�ĸ������͵����ݣ������������
	//gabor1->conv_img(&IplImage(img), reimg, CV_GABOR_MAG);
	////Ȼ������Щ���������ǲ��ܹ�������Ҷ�ͼ����ʽ�򵥵���ʾ�����������Ա�������һ��XML�ļ��С�
	//cvSave( "reimg.xml", (IplImage*)reimg, NULL, NULL, cvAttrList(0,0)); 
	//cvDestroyWindow("Magnitude Response");  


	///////////////////////////////////////////////////////////
	//	20130804 begin
	///////////////////////////////////////////////////////////
	////	file rename ��Ԫ����(�ѳɹ�����Ҫ������)
	//vector<string> imageFileList;
	//string imageDir = "H:/360/face_urls/";
	//getFileLocList(imageDir,imageFileList);
	//int index=0;
	//for(vector<string>::iterator it = imageFileList.begin(); it!=imageFileList.end(); ++it){
	//	index++;
	//	stringstream ss;
	//	ss<<index;
	//	string strIndex = ss.str();
	//	string newImageName = strIndex + ".jpg";
	//	rename((*it).c_str(),(imageDir+newImageName).c_str());
	//}

	//////////////////////////////////////////////////
	////	Mat���ݽṹ����
	//Mat test(Mat::ones(2,2,CV_8UC1));
	//test.convertTo(test,CV_32FC1);
	//test /= cvRound(3);
	//cout<<test<<endl;

	//////////////////////////////////////////////////
	////	����lbp������Ԫ���� ver 1.1
	//Mat lbpFpHist = lbpFp::getFpHistogram(image,256);
	//string loc = "D:/test.txt";
	//fpRecorder::writeToText(lbpFpHist,loc);

	////////////////////////////////////////////////////////
	////		generate image database lbp fp group matrix
	//string imageLocDir = "E:/360/face/face_urls/";
	//vector<string> imageLocList;
	//getFileLocList(imageLocDir,imageLocList);
	//Mat lbpFpGroupMatrix = fpGrouper::getLbpFpGroupMatrix(imageLocList);
	////	lbp fp group matrix to xml file
	//FileStorage fs("D:/lbpFpMatrix.xml",FileStorage::WRITE);
	//fs<<"lbpFpMatrix"<<lbpFpGroupMatrix;

	////	read fp group matrix
	//cout<<"begin"<<endl;
	//FileStorage fs("D:/lbpFpMatrix.xml",FileStorage::READ);
	//Mat lbpFpGroupMatrix;
	//cout<<"ready"<<endl;
	//fs["lbpFpMatrix"]>>lbpFpGroupMatrix;
	//cout<<"done"<<endl;
	//cout<<"rows:"<<lbpFpGroupMatrix.rows<<endl;
	//cout<<"cols:"<<lbpFpGroupMatrix.cols<<endl;
	//fs.release();

	//////////////////////////////////////////////////////////
	////	lbp PCA��Ԫ����,ȡǰ16����������ֵ����256ά����16ά������ֵ����80.12%
	//PCA pca(lbpFpGroupMatrix,Mat(),CV_PCA_DATA_AS_ROW,16);
	//cout<<"pca eigen values:"<<pca.eigenvalues<<endl;
	//fs.open("D:/lfgmEigenValues.xml",FileStorage::WRITE);
	//fs<<"lfgmEigenValues"<<pca.eigenvalues;
	//fs.release();

	//fs.open("D:/lfgmEigenVectors.xml",FileStorage::WRITE);
	//fs<<"lfgmEigenVectors"<<pca.eigenvectors;
	//fs.release();

	//// ����ֵ��������.step1:��������ֵ�ĺ�
	//Mat tmpSum(1,1,pca.eigenvalues.type());
	//reduce(pca.eigenvalues,tmpSum,0,CV_REDUCE_SUM);
	//cout<<"tmpSum"<<tmpSum<<endl;
	//
	//fs.open("D:/eigenValuesSum.xml",FileStorage::WRITE);
	//fs<<"eigenValuesSum"<<tmpSum;
	//fs.release();
	////	����ֵ�������㡣step2:��������ֵ��ռ����
	//Mat eigenValueProp(1,pca.eigenvalues.cols,pca.eigenvalues.type());
	//eigenValueProp = pca.eigenvalues / tmpSum;
	//fs.open("D:/lfgmEigenValueProp.xml",FileStorage::WRITE);
	//fs<<"eigenValueProp"<<eigenValueProp;
	////	����ֵ�������㡣step3:��������ֵ��������
	//Mat eigenValuePropAscend(eigenValueProp);
	//for (int i=1; i<eigenValuePropAscend.rows; i++ ){
	//	eigenValuePropAscend.at<float>(i,0) += eigenValuePropAscend.at<float>(i-1,0);
	//}
	//fs<<"eigenValuePropAscend"<<eigenValuePropAscend;
	//fs.release();

	////	����pcaӳ������������,�����ʱ�ܳ�����Լ2Сʱ����
	//Mat lfgmProjected;
	//for ( int i=0; i<lbpFpGroupMatrix.rows; i++){
	//	pca.project(lbpFpGroupMatrix,lfgmProjected);
	//}
	//fs.open("D:/lfgmProjected.xml",FileStorage::WRITE);
	//fs<<"lfgmProjected"<<lfgmProjected;
	//fs.release();

	//////////////////////////////////////////////////////
	////	ͼ���С��һ����128*128
	//const string imageDir = "H:/360/face_urls/";
	//const string dstDir = "E:/360/face/face_urls_unified/";
	//const Size dstSize(128,128);
	//vector<string> imageLocList;
	//getFileLocList(imageDir,imageLocList);
	//for ( vector<string>::iterator it = imageLocList.begin(); it != imageLocList.end(); ++it ){
	//	Mat src = imread(*it);
	//	Mat dst;
	//	resize(src,dst,dstSize);
	//	imwrite(*it,dst);
	//}

	//////////////////////////////////////////////////////////////////
	////	GaborFpMatrix ���ɵ�Ԫ����
	//FileStorage fs;
	//const string imageDir = "H:/360/face_urls/";
	//vector<string> imageLocList;
	//getFileLocList(imageDir,imageLocList);
	//Mat gaborFpGroupMatrix;
	//gaborFpGroupMatrix = fpGrouper::getGaborFpGroupMatrix(imageLocList);
	//fs.open("H:/gaborFpGroupMatrix.xml",FileStorage::WRITE);
	//fs<<"gaborFpGroupMatrix"<<gaborFpGroupMatrix;
	//fs.release();

	///////////////////////////////////////////////////////////////////
	//	����gabor��������
	//FileStorage fs;
	//fs.open(global::gabor::loc::fgmLoc,FileStorage::READ);
	//Mat gfgm;
	//fs[global::gabor::tag::fpGroupMatrix]>>gfgm;
	//fs.release();
	////	����ƽ��ֵ
	//gfgm.convertTo(gfgm,CV_32F);
	//Mat gfgmMean;
	//reduce(gfgm,gfgmMean,0,CV_REDUCE_AVG);
	//fs.open(global::gabor::loc::meanLoc,FileStorage::WRITE);
	//fs<<global::gabor::tag::mean<<gfgmMean;
	//fs.release();
	////	gabor��������ÿһ�ж���ȥƽ��ֵ
	//Mat meanMatrix;
	//for( int i=0; i<gfgm.rows; i++){
	//	meanMatrix.push_back(gfgmMean);
	//}
	//Mat test = gfgm - meanMatrix;
	//fs.open(global::test::loc::loc,FileStorage::WRITE);
	//cout<<global::test::loc::loc<<endl;
	//fs<<global::test::tag::tag<<test;
	//fs.release();

	////	����gabor��������Э����
	//Mat gfgm;
	//FileStorage fs;
	//fs.open(global::gabor::loc::fgmLoc,FileStorage::READ);
	//fs[global::gabor::tag::fpGroupMatrix]>>gfgm;
	//gfgm.convertTo(gfgm,CV_32F);
	//Mat gfgmCov,mean;
	//calcCovarMatrix(gfgm,gfgmCov,mean,CV_COVAR_ROWS | CV_COVAR_NORMAL);
	//fs.open(global::gabor::loc::covarLoc,FileStorage::WRITE);
	//fs<<global::gabor::tag::covar<<gfgmCov;
	//fs.release();

	////	calculate and save normalization of gabor finger print group matrix 
	//Mat gfgm;	//decleration of 'Gabor Fingerprint Group Matrix'
	//FileStorage fs;
	//fs.open(global::gabor::loc::fgmLoc,FileStorage::READ);
	//fs[global::gabor::tag::fpGroupMatrix]>>gfgm;	//read data into gfgm
	//fs.release();
	//gfgm.convertTo(gfgm,CV_64F);

	//Mat covar;	//decleration of covariance matrix of gfgm
	//Mat mean; //decleration of mean of gfgm;
	//calcCovarMatrix(gfgm,covar,mean,CV_COVAR_ROWS | CV_COVAR_NORMAL);
	//covar /= static_cast<double>(gfgm.rows);
	//Mat stdDev;	//decleration of stdandard deviation of gfgm
	//stdDev.create(1,covar.cols,CV_64F);
	//for ( int i=0; i<covar.rows; i++){
	//	stdDev.at<double>(0,i) = sqrt(covar.at<double>(i,i));
	//	cout<<"calculate standard deviation of column "<<i<<endl;
	//}

	//Mat normGfgm;	// decleration of normalized gfgm
	//normGfgm.create(gfgm.rows,gfgm.cols,CV_64F);
	//gfgm.copyTo(normGfgm);
	//for ( int i=0; i<normGfgm.rows; i++ ){	//calculate normGfgm
	//	mean.convertTo(mean,normGfgm.type());
	//	normGfgm.row(i) -= mean;
	//	cout<<"substract mean from row "<<i<<endl;
	//}
	//for ( int i=0; i<normGfgm.cols; i++ ){
	//	normGfgm.col(i) /= stdDev.at<double>(0,i);	//calculate normGfgm
	//	cout<<"devide standard deviation from column "<<i<<endl;
	//}
	//
	//fs.open(global::gabor::loc::normGfgm,FileStorage::WRITE);	//save normGfgm
	//fs<<global::gabor::tag::normGfgm<<normGfgm;
	//fs.release();

	//////////////////////////////////////////////////////////////////
	////	LbpFpMatrix generation
	//FileStorage fs;
	//const string imageDir = "H:/360/face_urls/";
	//vector<string> imageLocList;
	//getFileLocList(imageDir,imageLocList);
	//Mat lbpFpGroupMatrix;
	//lbpFpGroupMatrix = fpGrouper::getLbpFpGroupMatrix(imageLocList);
	//fs.open(global::lbp::loc::fgmLoc,FileStorage::WRITE);
	//fs<<global::lbp::tag::fpGroupMatrix<<lbpFpGroupMatrix;
	//fs.release();

	////	calculate and save normalization of Lbp finger print group matrix 
	//Mat lfgm;	//decleration of 'Lbp Fingerprint Group Matrix'
	//FileStorage fs;
	//fs.open(global::lbp::loc::fgmLoc,FileStorage::READ);
	//fs[global::lbp::tag::fpGroupMatrix]>>lfgm;	//read data into lfgm
	//fs.release();
	//lfgm.convertTo(lfgm,CV_64F);

	//Mat covar;	//decleration of covariance matrix of lfgm
	//Mat mean; //decleration of mean of lfgm;
	//calcCovarMatrix(lfgm,covar,mean,CV_COVAR_ROWS | CV_COVAR_NORMAL);
	//covar /= static_cast<double>(lfgm.rows);
	//Mat stdDev;	//decleration of stdandard deviation of lfgm
	//stdDev.create(1,covar.cols,CV_64F);
	//for ( int i=0; i<covar.rows; i++){
	//	stdDev.at<double>(0,i) = sqrt(covar.at<double>(i,i));
	//	cout<<"calculate standard deviation of column "<<i<<endl;
	//}

	//Mat normlfgm;	// decleration of normalized lfgm
	//normlfgm.create(lfgm.rows,lfgm.cols,CV_64F);
	//lfgm.copyTo(normlfgm);
	//for ( int i=0; i<normlfgm.rows; i++ ){	//calculate normlfgm
	//	mean.convertTo(mean,normlfgm.type());
	//	normlfgm.row(i) -= mean;
	//	cout<<"substract mean from row "<<i<<endl;
	//}
	//for ( int i=0; i<normlfgm.cols; i++ ){
	//	normlfgm.col(i) /= stdDev.at<double>(0,i);	//calculate normlfgm
	//	cout<<"devide standard deviation from column "<<i<<endl;
	//}
	//
	//fs.open(global::lbp::loc::normLfgm,FileStorage::WRITE);	//save normlfgm
	//fs<<global::lbp::tag::normLfgm<<normlfgm;
	//fs.release();

	Mat test1 = Mat::zeros(2,2,CV_8UC1);
	Mat test2 = Mat::ones(2,3,CV_8UC1);
	cout<<"test1"<<test1<<endl;
	cout<<"test2"<<test2<<endl;

	hconcat(test1,test2,test1);
	cout<<"test1"<<test1<<endl;
	system("pause");
	return 0;
}

int getFileLocList( const string& dir, vector<string>& fileLocList )
{
	long handle;
	_finddata_t fileInfo;
	{
		string vir_fir = dir + "*.*";
		handle = _findfirst(vir_fir.c_str(),&fileInfo);
		if ( handle==-1 )
		{
			cout<<dir<<" getFileList failed."<<endl;
			return -1;
		}
	}
	do 
	{
		if ( fileInfo.attrib==_A_SUBDIR || fileInfo.attrib==_A_HIDDEN )
		{
			continue;
		}

		string fileLoc = dir + '/' + fileInfo.name;
		fileLocList.push_back(fileLoc);
	} while (!_findnext(handle,&fileInfo));
	_findclose(handle);

	return 0;
}