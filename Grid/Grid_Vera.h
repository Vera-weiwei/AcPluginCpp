#pragma once
#include "StdAfx.h"

class POLADLL_GRID_API getexistedgridinformation
{
public:

	static bool gethorid(AcDbObjectIdArray HORLine, AcDbObjectIdArray& HORLineid);//�õ�����������id
	static bool getverid(AcDbObjectIdArray HORLine, AcDbObjectIdArray& verLineid);//�õ�����������id
	static bool gethorspace(AcDbObjectIdArray HORLine, std::vector<double>space1);//��������ߵ�id���õ������߼��
	static bool getverspace(AcDbObjectIdArray HORLine, std::vector<double>space2);//���������ߵ�id���õ������߼��
	static std::vector<double> roundspace(std::vector<double>space1,int mod);

};

class POLADLL_GRID_API drawline
{
public:


};