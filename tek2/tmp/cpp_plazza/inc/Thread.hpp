#ifndef THREAD
#define THREAD

#include <iostream>
#include <thread>

class Thread
{
public:
	Thread(){};
	~Thread();
	bool init(void (*)(void));

private:
	std::thread *core;
};

#endif