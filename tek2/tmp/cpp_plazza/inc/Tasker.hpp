#ifndef TASKER
#define TASKER

#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <vector>
#include "Thread.hpp"
#include "Pipe.hpp"

class Tasker
{
public:
  Tasker(){};
  ~Tasker();
  bool init(int);

private:
  std::vector<Thread> threads;
  std::vector<Pipe> pipes;
  pid_t id;
};

#endif