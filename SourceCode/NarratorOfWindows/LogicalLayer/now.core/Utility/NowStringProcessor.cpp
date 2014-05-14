#include "NowStringProcessor.h"

//std::string NowStringProcessor::IntToStlString( const int& number )
//{
//	return to_string((long)number);
//}


wstring NowStringProcessor::Utf8ToStlWString( const string& pUtfString)
{
	wstring stlString(pUtfString.begin(), pUtfString.end());
	//MAKE_WIDEPTR_FROMUTF8(pString, pUtfString);
	//stlString = pString;
	return stlString;
}

std::string NowStringProcessor::wstringTostring( const wstring & inString )
{
	string result = "";
	std::string s((const char*)&inString[0], sizeof(wchar_t)/sizeof(char)*inString.size());
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 2 == 0)
		{
			result += s.at(i);
		}
	}

	return result;
}

//
//void NowStringProcessor::Utf8ToStlWStringN( char const* pUtfString, ULONG length )
//{
//	wstring stlString;
//	MAKE_WIDEPTR_FROMUTF8N(pString, pUtfString, length);
//	stlString = pString;
//	return stlString;
//}

vector<string>* NowStringProcessor::split(const std::string& source, char delim)
{
	vector<string>* vecResult = new vector<string>();
	stringstream ss(source);
	string item;
	while (getline(ss, item, delim)) {
		vecResult->push_back(item);
	}
	return vecResult;
}

vector<wstring>* NowStringProcessor::split(const std::wstring& source, wchar_t delim)
{
	vector<wstring>* vecResult = new vector<wstring>();
	wstring item = L"";

	for (int i = 0; i < source.length(); i++)
	{
		if (source.at(i) == delim)
		{
			vecResult->push_back(item);
			item = L"";
		}
		else
		{
			item += source.at(i);
		}
	}

	if (!item.empty())
	{
		vecResult->push_back(item);
	}
	return vecResult;
}

vector<string>* NowStringProcessor::split( const std::string& source, const std::string& delimiter )
{
	vector<string>* vecResult = new vector<string>();
	std::string strSource = source;
	size_t pos = 0;
	std::string token;
	while ((pos = strSource.find(delimiter)) != std::string::npos) {
		token = strSource.substr(0, pos);
		vecResult->push_back(token);
		strSource.erase(0, pos + delimiter.length());
	}
	vecResult->push_back(strSource);
	return vecResult;
}

vector<wstring>* NowStringProcessor::split( const std::wstring& source, const std::wstring& delimiter )
{
	vector<wstring>* vecResult = new vector<wstring>();
	std::wstring strSource = source;
	size_t pos = 0;
	std::wstring token;
	while ((pos = strSource.find(delimiter)) != std::wstring::npos) {
		token = strSource.substr(0, pos);
		vecResult->push_back(token);
		strSource.erase(0, pos + delimiter.length());
	}
	vecResult->push_back(strSource);
	return vecResult;
}


bool NowStringProcessor::compareIgnoreCase( const string& strFirst, const string& strSecond )
{
	bool blnResult = false;
	if (toLowerCase(strFirst).compare(toLowerCase(strSecond)) == 0)
	{
		blnResult = true;
	}
	return blnResult;
}

std::string NowStringProcessor::toLowerCase( const string& strNormal )
{
	string strReturn = strNormal;
	std::transform(strReturn.begin(), strReturn.end(), strReturn.begin(), ::tolower);
	return strReturn;
}