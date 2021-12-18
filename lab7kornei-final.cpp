// lab7kornei-final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "bridge.h"
#include "bridge.cpp"
#include "facade.h"
#include "facade.cpp"
#include "iterator.cpp"
#include "iterator.h"
#include "flyinfexp.h"
#include "flyinfexp.cpp"
#include "adapter.h"
#include "adapter.cpp"
#include "string.h"
#include <iostream>
#include <map>

using namespace std;

class extHydrate {
};


class extWeather : public extHydrate {
public:
	weatherCounter *weather = new weatherCounter();
};

class extSnow : public extHydrate {
public:
	snowCounter *snow = new snowCounter();
};

class extIce : public extHydrate {
public:
	iceCounter *ice = new iceCounter();
};



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	metCounter *conto = new metCounter();
	Watch *seeyo = new Watch(36, 116);
	flyweightFactory *eski = new flyweightFactory();
	printf("Bridge\n\n");
	printf("С обычного наблюдателя, flow:\n\n");
	seeyo->watchi->graphFlow();
	printf("С как бы прокси-наблюдателя, forecast:\n\n");
	seeyo->proxywatchi->graphForecast();
	conto->init(35, 123.4);
	conto->fieldWay->init(30.4);
	printf("Flyweight\n\n");
	eski->creati("Береговая", "snow", 1, 1, 123.4, 35);
	eski->creati("Береговая", "snow", 2, 1, 125, 37);
	eski->creati("Ленточный бор", "weather", 1, 1, 125, 37);
	printf("Facade\n\n");
	Facade *k = new Facade();
	k->FacadeWater->waterLvl();
	printf("Information expert\n\n");
	conto->fieldWay->cyclonsCount(conto->atm, conto->temp);
	conto->fieldWay->atFieldCount(conto->atm, conto->temp);
	conto->fieldWay->tempFieldCount(conto->atm, conto->temp);
	_getch();
	return 0;
}