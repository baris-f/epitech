#include "Teddy.hh"

Teddy::Teddy(std::string const& name) :
  Toy(name, "Teddy")
{
}

Teddy::Teddy(Teddy const &other) : Toy(other){
}

Teddy::~Teddy()
{
}

void	Teddy::isTaken()
{
  std::cout << "gra hu" << std::endl;
  Object::isTaken();
}
