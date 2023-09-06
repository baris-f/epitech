//
// carrier.cpp for carrer in /home/baris_f/rendu/tek2/cpp_d08/ex03
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 11 22:02:34 2017 baris_f
// Last update Wed Jan 11 23:16:08 2017 baris_f
//

#include "carrier.hh"

Carrier::Carrier(std::string Id)
  : _Attack(100), _Toughness(90)
{
  _Id = Id;
  _Energy = 300;
  _Speed = 0;
  for(int i = 0; i < 5; i++)
    _Droids[i] = NULL;
}

Carrier::~Carrier(){
  for(int i = 0; i < 5; i++)
    _Droids[i] = NULL;
}

Droid*		Carrier::operator<<(Droid* droid)
{
  int	i;

  for(i = 0; _Droids[i] != NULL && i < 5; i++);
  if (i < 5)
    _Droids[i] = droid;
  droid = NULL;
  return (droid);
}

Droid const*	Carrier::operator>>(Droid* const droid)
{
  int	i;

  for(i = 0; _Droids[i] != droid && i < 5; i++);
  if (i < 5)
    _Droids[i] = NULL;
  return (droid);
}

Droid*		Carrier::operator[](int const index) const{
  return (_Droids[index]);
}

Carrier&	Carrier::operator~(){
  if (nbDroids() == 0)
    _Speed = 0;
  else
    _Speed = 100 - (nbDroids() * 10);
  return (*this);
}

bool		Carrier::operator()(int x, int y)
{
  if (nbDroids() == 0 || _Energy < (abs(x) + abs(y)) * (10 + (nbDroids())))
    return (false);
  _Energy -= (abs(x) + abs(y)) * (10 + (nbDroids()));
  return (true);
}

size_t  Carrier::operator<<(size_t &change)
{
  if (getEnergy() + change > 600)
    {
      change = getEnergy() + change - 600;
      setEnergy(600);
    }
  else
    {
      setEnergy(getEnergy() + change);
      change = 0;
    }
  return (change);
}

std::ostream&   operator<<(std::ostream& os, Carrier const& carrier)
{
  os << "Droid '" << carrier.getId() << "', Droid(s) on board:" << std::endl;

  for(int i = 0; i < 5; i++)
    {
      std::cout << "[" << i << "] : ";
      if (carrier[i] != NULL)
	std::cout << carrier[i] << std::endl;
      else
	std::cout << "Free" << std::endl;
    }
  return (os);
}

size_t		Carrier::nbDroids() const
{
  size_t	nb = 0;

  for(int i = 0; i < 5; i++)
    if(_Droids[i] != NULL)
      nb++;
  return (nb);
}

size_t		Carrier::getSpeed() const { return (_Speed);}
void		Carrier::setSpeed(size_t Speed) { _Speed = Speed;}
size_t		Carrier::getEnergy() const { return (_Energy);}
void		Carrier::setEnergy(size_t Energy) { _Energy = Energy;}
std::string		Carrier::getId() const { return (_Id);}
void		Carrier::setId(std::string Id) { _Id = Id;}

int main()
{
    Carrier c("HellExpress");
    Droid *d1= new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    c(4, 2);
    std::cout << c << std::endl;
    c(-15, 4);
    std::cout << c << std::endl;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std::cout << c << std::endl;
    return (0);
}
