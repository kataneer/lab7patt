#include "stdafx.h"
#include "math.h"
#include "adapter.h"
#include "iterator.cpp"
#include "iterator.h"
#include <iostream>

Facade::Facade()  //Facade: ��������� ������� ������������ ����� ���������������
{
	Waters *FacadeWater = new Waters();
	aggregate <string> *FacadeAggr = new aggregate <string> ();
}