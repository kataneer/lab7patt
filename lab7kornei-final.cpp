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

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	printf("Bridge\n\n");
//обращаемся через экземпляр класса Watch к методу graphFlow у класса Watcher и graphForecast класса ProxyWatcher для проверки связей
	Watch *seeyo = new Watch(36, 116);
	printf("С обычного наблюдателя, flow:\n\n");
	seeyo->watchi->graphFlow();                 
	printf("С как бы прокси-наблюдателя, forecast:\n\n");
	seeyo->proxywatchi->graphForecast();
	printf("Flyweight\n\n");
//создаем фабрику eski, через встроенный метод создания - множество объектов-счетчиков с разными параметрами и выводим информацию по ним
       flyweightFactory *eski = new flyweightFactory();
	eski->creati("Береговая", "snow", 1, 1, 123.4, 35);
	eski->creati("Береговая", "snow", 2, 1, 125, 37);
	eski->creati("Ленточный бор", "weather", 1, 1, 125, 37);
	printf("Facade\n\n");
//создаем новый экземпляр класса Facade и обращаемся через унифицированный интерфейс к методу waterLvl из связанного класса
	Facade *k = new Facade();
	k->FacadeWater->waterLvl();
	printf("Information expert\n\n");
//подсчитываем циклоны, поля давлений и температуры в отдельном классе metCyclons и его методах подсчета cyclonsCount, atFieldCount и tempFieldCount через экземпляр класса fieldWay
	metCounter *conto = new metCounter();
	conto->init(35, 123.4);
	conto->fieldWay->init(30.4);
	conto->fieldWay->cyclonsCount(conto->atm, conto->temp);
	conto->fieldWay->atFieldCount(conto->atm, conto->temp);
	conto->fieldWay->tempFieldCount(conto->atm, conto->temp);
	_getch();
	return 0;
}

