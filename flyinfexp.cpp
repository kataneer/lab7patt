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
	printf("\nСчетчик Inf.Expert: циклоны\n\n");
}

void metCyclons::atFieldCount(int atm, float temp)
{
	printf("%f\n", atm * powl(times, 2) / temp);
	printf("\nСчетчик Inf.Expert: поля давления\n\n");
}

void metCyclons::tempFieldCount(int atm, float temp)
{
	printf("%f\n", powl(atm, 2) * times / temp);
	printf("\nСчетчик Inf.Expert: поля температуры\n\n");
}


