#include "stdafx.h"
#include "math.h"
#include "adapter.h"
#include "iterator.cpp"
#include "iterator.h"
#include <iostream>
//подключаем соответствующие классы для управления

Facade::Facade()  //Facade: управляем разными интерфейсами через унифицированный
{
	Waters *FacadeWater = new Waters();
	aggregate <string> *FacadeAggr = new aggregate <string> ();
}
