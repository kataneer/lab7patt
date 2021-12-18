#ifndef __flyinfexp
#define __flyinfexp
#include "string.h"
#include <iostream>
#include <map>

using namespace std;


class metCyclons {  //���������� Information Expert: ��������� ����� metCyclons ��� ��������
public:
	float times;
	void init(float t);
	void cyclonsCount(int atm, float temp);
	void atFieldCount(int atm, float temp);
	void tempFieldCount(int atm, float temp);
};

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
		printf("\n������� �������\n\n");
	}
};

class snowCounter : public metCounter {
public:
	void meteoCount()
	{
		printf("%f\n", atm - temp);
		printf("\n������� �����\n\n");
	}
};


class iceCounter : public metCounter {
public:
	void meteoCount()
	{
		printf("%f\n", atm / temp);
		printf("\n������� ����\n\n");
	}
};

class flyweightFactory {  //���������� flyweight: ������� �������� �� �������������
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
			printf("������ ����� ������� �����.\n");
			cout << "�������: " << nameCount << ", �����: " << number << "\n" << endl;
		}
		else if (strcmp(type, "ice") == 0)
		{
			count = new iceCounter;
			printf("������ ����� ������� ����.\n");
			cout << "�������: " << nameCount << ", �����: " << number << "\n" << endl;
		}
		else if (strcmp(type, "weather") == 0)
		{
			count = new weatherCounter;
			printf("������ ����� ������� ������.\n");
			cout << "�������: " << nameCount << ", �����: " << number << "\n" << endl;
		}
		avgRiv[pos] = count;
	}
};


#endif
