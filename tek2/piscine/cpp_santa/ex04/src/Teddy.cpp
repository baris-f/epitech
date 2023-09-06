#include "Teddy.hh"

Teddy::Teddy(std::string const& name) :
  Object(name, "Tedy", 0, false),Toy(name, "Teddy")
{
}

Teddy::~Teddy()
{
}

void	Teddy::isTaken()
{
  std::cout << "gra hu" << std::endl;
  Object::isTaken();
}
