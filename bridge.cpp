#include "stdafx.h"
#include "math.h"
#include "flyinfexp.h"
#include <iostream>

using namespace std;

Watch::Watch(float a, float b)  //Bridge: отделяем абстракцию Watch от реализаций Watcher и ProxyWatcher
{
	watchi = new Watcher(a, b);
	proxywatchi = new ProxyWatcher(a, b);
}

void Watcher::graphFlow()
{
	printf("%f\n\n", square + speed);
}

void Watcher::graphForecast()
{
	printf("%f\n\n", square * speed);
}

Watcher::Watcher(float a, float b)
{
	square = a;
	speed = b;
}

void ProxyWatcher::graphFlow()
{
	ras->graphFlow();
}

void ProxyWatcher::graphForecast()
{
	ras->graphForecast();
}

ProxyWatcher::ProxyWatcher(float a, float b)
{
	ras = new Watcher(a, b);
}

void Watch::graphFlow()
{
	watchi->graphFlow();
}

void Watch::graphForecast()
{
	watchi->graphForecast();
}

void Watch::graphPFlow()
{
	proxywatchi->graphFlow();
}

void Watch::graphPForecast()
{
	proxywatchi->graphForecast();
}
