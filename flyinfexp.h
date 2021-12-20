#ifndef __flyinfexp
#define __flyinfexp
#include "string.h"
#include <iostream>
#include <map>

using namespace std;


class metCyclons {  //реализация Information Expert: отдельный класс metCyclons для расчетов в классе metCounter
public:
	float times;
	void init(float t);
	void cyclonsCount(int atm, float temp);
	void atFieldCount(int atm, float temp);
	void tempFieldCount(int atm, float temp);
};

//счетчики - общий класс metCounter и его подклассы для льда, снега и погоды
class metCounter {
protected:
	char *name = new char[];
	char *type = new char[];
	int number;
public:
	metCyclons *fieldWay;
	metCounter();
	int atm;
	float temp;
	void initMet(char *nm, char *tp, int num)
	{
		name = nm;
		type = tp;
		number = num;
	}
	void init(int a, float b)
	{
		atm = a;
		temp = b;
	}
	void meteoCount();
};

class weatherCounter : public metCounter {
public:
	void meteoCount()
	{
		printf("%f\n", atm + 2 * temp);
		printf("%f\n", atm + 2 / temp);
		printf("\nСчетчик осадков\n\n");
	}
};

class snowCounter : public metCounter {
public:
	void meteoCount()
	{
		printf("%f\n", atm - temp);
		printf("\nСчетчик снега\n\n");
	}
};


class iceCounter : public metCounter {
public:
	void meteoCount()
	{
		printf("%f\n", atm / temp);
		printf("\nСчетчик льда\n\n");
	}
};

class flyweightFactory {  //реализация flyweight: создаем счетчики по необходимости
private:
	typedef std::map<int, metCounter*> counters;
	counters avgRiv;
public:
	flyweightFactory() {};
	void creati(char nameCount[], char type[], int number, int pos, int atm, float temp)
	{
		metCounter* count = new metCounter();
		count->initMet(nameCount, type, number);
		count->init(atm, temp);
		if (strcmp(type, "snow") == 0)
		{
			count = new snowCounter;
			printf("Создан новый счетчик снега.\n");
			cout << "Участок: " << nameCount << ", номер: " << number << "\n" << endl;
		}
		else if (strcmp(type, "ice") == 0)
		{
			count = new iceCounter;
			printf("Создан новый счетчик льда.\n");
			cout << "Участок: " << nameCount << ", номер: " << number << "\n" << endl;
		}
		else if (strcmp(type, "weather") == 0)
		{
			count = new weatherCounter;
			printf("Создан новый счетчик погоды.\n");
			cout << "Участок: " << nameCount << ", номер: " << number << "\n" << endl;
		}
		avgRiv[pos] = count;
	}
};


#endif
