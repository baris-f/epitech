#include "Thread.hpp"

Thread::~Thread()
{
	core->join();
	// std::cout << "thread joined" << std::endl;
}

bool	Thread::init(void(*fct)(void))
{
	core = new std::thread(fct);
	return (true);
}
