#include "Teddy.hh"

Teddy::Teddy(std::string const& name) :
  Object(name, "Toy", 0, false),Toy(name, "Toy")
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
