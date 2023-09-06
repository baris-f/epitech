//
// droid.cpp for droid in /home/baris_f/rendu/tek2/cpp_d08/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 11 10:38:55 2017 baris_f
// Last update Wed Jan 11 23:54:39 2017 baris_f
//

#include "droid.hh"

Droid::Droid(std::string serial)
  : _Attack(25), _Toughness(15)
{
  _Id = serial;
  _Energy = 50;
  _Status = new std::string("Standing by");
  std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid& d)
  : _Id(d._Id), _Energy(d._Energy), _Attack(d._Attack),
    _Toughness(d._Toughness), _Status(d._Status)
{
  std::cout << "Droid '" << getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(){
  std::cout << "Droid '" << getId() << "' Destroyed" << std::endl;
}

std::string   Droid::getId() const { return (_Id);};
void          Droid::setId(std::string Id){_Id = Id;};
size_t        Droid::getEnergy() const{ return (_Energy);};
void          Droid::setEnergy(size_t Energy){ _Energy = Energy;};
size_t        Droid::getAttack() const { return(_Attack);};
size_t        Droid::getToughness() const{ return(_Toughness);};
std::string*  Droid::getStatus() const{
  if (_Status)
    return(_Status);
  return (NULL);
};
void          Droid::setStatus(std::string* Status){
  if (_Status)
    delete _Status;
  _Status = Status;
}

Droid&	Droid::operator=(Droid const &other)
{
  if (other != *this)
    {
      setId(other.getId());
      setEnergy(other.getEnergy());
      setStatus(other.getStatus());
    }
  return *this;
}

bool	Droid::operator==(Droid const &other) const
{
  if (_Id == other._Id && _Energy == other._Energy && _Attack == other._Attack && _Toughness == other._Toughness && *_Status == *(other._Status))
    return (true);
  return (false);
}

bool	Droid::operator!=(Droid const &other) const
{
  if (_Id == other._Id && _Energy == other._Energy && _Attack == other._Attack && _Toughness == other._Toughness && *_Status == *(other._Status))
    return (false);
  return (true);
}

size_t	Droid::operator<<(size_t &change)
{
  if (getEnergy() + change > 100)
    {
      change = getEnergy() + change - 100;
      setEnergy(100);
    }
  else
    {
      setEnergy(getEnergy() + change);
      change = 0;
    }
  return (change);
}

std::ostream&	operator<<(std::ostream& os, Droid const& droid)
{
  os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
  return (os);
}
/*
int     main()
{
  Droid d;
  Droid d1("Avenger");
  size_t Durasel = 200;

  std::cout << d << std::endl;
  std::cout << d1 << std::endl;
  d = d1;
  d.setStatus(new std::string("Kill Kill Kill!"));
  d << Durasel;
  std::cout << d << "--" << Durasel << std::endl;
  Droid d2 = d;
  d.setId("Rex");
  std::cout  <<(d2 != d) << std::endl;
  return (0);
}
*/
