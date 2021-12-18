#ifndef __facade
#define __facade

#include "adapter.h"
#include "iterator.h"

using namespace std;

class Facade {
public:
	string S;
	Waters *FacadeWater;
	aggregate <string> *FacadeAggr;
	Facade();
};

#endif

