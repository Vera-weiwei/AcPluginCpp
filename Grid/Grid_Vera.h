#pragma once
#include "StdAfx.h"

class POLADLL_GRID_API getexistedgridinformation
{
public:

	static bool gethorid(AcDbObjectIdArray HORLine, AcDbObjectIdArray& HORLineid);//得到横向线所有id
	static bool getverid(AcDbObjectIdArray HORLine, AcDbObjectIdArray& verLineid);//得到竖向线所有id
	static bool gethorspace(AcDbObjectIdArray HORLine, std::vector<double>space1);//输入横向线的id，得到横向线间距
	static bool getverspace(AcDbObjectIdArray HORLine, std::vector<double>space2);//输入竖向线的id，得到竖向线间距
	static std::vector<double> roundspace(std::vector<double>space1,int mod);

};

class POLADLL_GRID_API drawline
{
public:


};