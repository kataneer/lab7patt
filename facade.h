#include "adapter.h"
#include "iterator.h"

using namespace std;

class Facade {     //реализация Facade: управляем разными интерфейсами через унифицированный
public:
	string S; 
	Waters *FacadeWater;               //подключаем объекты разных классов
	aggregate <string> *FacadeAggr;
	Facade()
	{
		Waters *FacadeWater = new Waters();
		aggregate <string> *FacadeAggr = new aggregate <string>();
	}
	void waterLvl()
	{
		FacadeWater->waterLvl();
	}
	void underFlows()
	{
		FacadeWater->underFlows();
	}
	
	void end()
	{
		FacadeAggr->end();
	}
};

