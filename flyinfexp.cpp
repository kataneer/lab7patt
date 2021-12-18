#include "stdafx.h"
#include "math.h"
#include "flyinfexp.h"
#include "string.h"
#include <iostream>
#include <map>

using namespace std;

metCounter::metCounter()
{
	fieldWay = new metCyclons();
}

void metCyclons::init(float t)
{
	times = t;
}

void metCyclons::cyclonsCount(int atm, float temp)
{
	printf("%f\n", atm * times / temp);
	printf("\n������� Inf.Expert: �������\n\n");
}

void metCyclons::atFieldCount(int atm, float temp)
{
	printf("%f\n", atm * powl(times, 2) / temp);
	printf("\n������� Inf.Expert: ���� ��������\n\n");
}

void metCyclons::tempFieldCount(int atm, float temp)
{
	printf("%f\n", powl(atm, 2) * times / temp);
	printf("\n������� Inf.Expert: ���� �����������\n\n");
}


