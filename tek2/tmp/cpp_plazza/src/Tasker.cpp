#include "Tasker.hpp"

Tasker::~Tasker()
{
	id = getpid();
}

void test()
{
	// std::cout << "coucou" << std::endl;
}

bool Tasker::init(int n)
{
	id = 0;

	threads.resize(n);
	//  pipes.resize(n);
	for (int i = 0; i < n; i++)
	{
		threads[i].init(&test);
		// pipes[i].init(id, i);
	}
	return (true);
}
