//#include "stdafx.h"
#include "NowUtility.h"
#include "NowDevice.h"
#include "NowConstant.h"

vector<vector<string>*>* NowUtility::readData(const string& strFileName)
{
	if (strFileName.empty())
	{
		return NULL;
	}

	string strFullPath = "";
	string strDirectory = NowDevice::getEnvironmentVariable(NOW_DEBUG_DIRECTORY);
	if (strDirectory.empty())
	{
		strFullPath = NowDevice::getCurrentDirectory() + strFileName;
	}
	else
	{
		strFullPath = strDirectory + strFileName;
	}

	// + strFileName;
	vector<vector<string>*>* reRsult = new vector<vector<string>*>();
	string strTemp = "";
	ifstream infile;
	infile.open(strFullPath);
	while (!infile.eof())
	{
		getline(infile, strTemp); // Saves the line in strTemp.
		vector<string>* vectContentLine = split(strTemp, NOW_CHAR_EQUAL);  
		if(vectContentLine->size() == 2)
		{
			reRsult->push_back(vectContentLine);
		}
	}
	infile.close();
	return reRsult;
}

vector<string>* NowUtility::split(const std::string& source, char delim)
{
	vector<string>* vecResult = new vector<string>();// ectContentLinet;ing>();
	stringstream ss(source);
	string item;
	while (getline(ss, item, delim)) {
		vecResult->push_back(item);
	}
	return vecResult;
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