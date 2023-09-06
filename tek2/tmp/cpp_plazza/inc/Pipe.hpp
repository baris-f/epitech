#ifndef PIPE
#define PIPE

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>

class Pipe
{
  public:
	Pipe(){};
	~Pipe();
	bool init(int, int);
	void send(std::string);
	std::string receive();

  private:
	std::fstream fd;
};

#endif