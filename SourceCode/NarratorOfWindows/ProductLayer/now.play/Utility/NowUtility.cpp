#include "stdafx.h"
#include "NowUtility.h"
#include "NowDevice.h"
#include "NowConstant.h"

vector<vector<string>*>* NowUtility::readData(const string& strFileName)
{
	string strFullPath = NowDevice::getEnvironmentVariable(NOW_DEBUG_DIRECTORY) + strFileName;
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


//std::vector<std::string> split(const std::string &s, char delim) {
//	std::vector<std::string> elems;
//	split(s, delim, elems);
//	return elems;
//}