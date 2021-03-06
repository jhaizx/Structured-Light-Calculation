#ifndef _CSENSOR_H_
#define _CSENSOR_H_

#include <string>
#include <opencv2/opencv.hpp>
#include <strstream>
#include "StaticParameters.h"
#include "GlobalFunction.h"
#include "CStorage.h"

using namespace std;
using namespace cv;

// 传感器模块。
class CSensor
{
private:
	// 当前读取数据相关：
	int m_dataNum;
	int m_nowNum;
	string m_filePath;
	string m_fileName;
	string m_fileSuffix;

	// 总体数据：
	string m_groupDataPath;	// 一组数据的path
	string m_iFramePath;
	string m_cFramePath;
	string m_vGrayName;
	string m_vPhaseName;
	string m_dynaName;
	string m_dataFileSuffix;

	// 存储的相机图案
	Mat * m_dataMats;

public:
	CSensor();
	~CSensor();

	// 初始化传感器
	bool InitSensor();

	// 关闭传感器
	bool CloseSensor();

	// 读取图案
	// groupNum == 0：读取vGray数据
	// groupNum == 1：读取vPhase数据
	// groupNum == 2：读取dynaMat数据
	bool LoadDatas(int groupNum);

	// 释放已读取图案
	bool UnloadDatas();

	// 设置投影仪投影的图像
	bool SetProPicture(int nowNum);
	
	// 获取相机图像
	Mat GetCamPicture();
};

#endif