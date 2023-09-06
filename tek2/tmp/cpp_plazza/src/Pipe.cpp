#include "Pipe.hpp"

Pipe::~Pipe()
{
	fd.close();
}

bool Pipe::init(int pid, int tid)
{
	std::string file("plazza_p");

	file += pid + "t" + tid;
	mkfifo(file.c_str(), 0666);
	fd.open(file);
	return (true);
}

void Pipe::send(std::string s)
{
	fd.write(s.c_str(), s.length());
}

std::string Pipe::receive()
{
	std::string line;

	std::getline(fd, line);
	return (line);
}