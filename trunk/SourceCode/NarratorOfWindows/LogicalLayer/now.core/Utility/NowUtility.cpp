//#include "stdafx.h"
#include "NowUtility.h"
#include "NowDevice.h"
#include "NowConstant.h"
#include "NowStringProcessor.h"

vector<vector<wstring>*>* NowUtility::readData(const string& strFileName)
{
	vector<vector<wstring>*>* result = new vector<vector<wstring>*>();
	if (strFileName.empty())
	{
		return NULL;
	}

	string strFullPath = NowDevice::getInstallDirectory() + strFileName;

	vector<wstring>* tempData = NowDevice::getFileData(strFullPath);
	vector<wstring>::iterator it = tempData->begin();
	for (; it != tempData->end(); it++)
	{
		vector<wstring>* vectPair = NowStringProcessor::split(*it, L'=');
		if(vectPair != NULL)
		{
			if (vectPair->size() == 2)
			{
				result->push_back(vectPair);
			}
		}
	}
	
	return result;
}



void NowUtility::getRectData( vector<string>* data, int& left, int& top, int& widht, int& height )
{
	if (data->size() == 4)
	{
		left = atoi(data->at(0).c_str());
		top = atoi(data->at(1).c_str());
		widht = atoi(data->at(2).c_str());
		height = atoi(data->at(3).c_str());
	}
}

