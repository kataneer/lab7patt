#ifndef __bridge
#define __bridge

class Watcher {
public:
	float square;
	float speed;
	void graphFlow();
	void graphForecast();
	Watcher(float a, float b);
};

class ProxyWatcher {
private:
	Watcher *ras;
public:
	void graphFlow();
	void graphForecast();
	ProxyWatcher(float a, float b);
};

class Watch {
public:
	Watcher *watchi;
	ProxyWatcher *proxywatchi;
	Watch(float a, float b);
};


#endif
