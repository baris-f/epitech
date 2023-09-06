//
// droid.cpp for droid in /home/baris_f/rendu/tek2/cpp_d08/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 11 10:38:55 2017 baris_f
// Last update Wed Jan 11 23:56:19 2017 baris_f
//

#include "droid.hh"

Droid::Droid(std::string serial)
  : _Attack(25), _Toughness(15)
{
  _Id = serial;
  _Energy = 50;
  _Status = new std::string("Standing by");
  _BattleData = new DroidMemory;
  std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid& d)
  : _Id(d._Id), _Energy(d._Energy), _Attack(d._Attack),
    _Toughness(d._Toughness), _Status(d._Status)
{
  std::cout << "Droid '" << getId() << "' Activated, Memory Dumped" << std::endl;
}

/*Droid::Droid(Droid const& other)
  : _Attack(25), _Toughness(15)
{
  setId(other.getId());
  setEnergy(50);
  setStatus(other.getStatus());
  setBattleData(other.getBattleData());
  std::cout << "Droid '" << getId() << "' Activated, Memory Dumped" << std::endl;
}*/

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
void          Droid::setStatus(std::string Status){
  if (_Status)
    delete _Status;
  _Status = new std::string(Status);
}

DroidMemory	*Droid::getBattleData() const{ return (_BattleData);};
void		Droid::setBattleData(DroidMemory *data){ _BattleData = data;};


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
  if (*_Status == *(other._Status))
    return (true);
  return (false);
}

bool	Droid::operator!=(Droid const &other) const
{
  if (*_Status == *(other._Status))
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

bool            Droid::operator()(std::string const * task, size_t const Exp)
{
  std::string	tmp(task->c_str());

  if (getEnergy() <= 10)
    {
      setEnergy(0);
      setStatus(std::string("Battery Low"));
      return (false);
    }
  setEnergy(getEnergy() - 10);
  if (*_BattleData < Exp)
    {
      *_BattleData += Exp;
      setStatus(tmp + std::string(" - Failed!"));
      return (false);
    }
  setStatus(tmp + std::string(" - Completed!"));
  *_BattleData += Exp / 2;
  return (true);
}

std::ostream&	operator<<(std::ostream& os, Droid const& droid)
{
  os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
  return (os);
}

/*
int main()
{
  DroidMemory dm;
  DroidMemory dn;
  DroidMemory dg;
  dm += 42;
  DroidMemory dn1 = dm;
  std::cout << dm << std::endl;
  dn << dm;
  dn >> dm;
  dn << dm;
  std::cout << dn << std::endl;
  std::cout << dm << std::endl;
  dg = dm + dn1;

  Droid d("rudolf");
  Droid d2("gaston");
  size_t DuraSell = 40;
  d << DuraSell;
  d.setStatus(new std::string("having some reset"));
  d2.setStatus(new std::string("having some reset"));
  if (d2 != d && !(d == d2))
    std::cout << "a droid is a droid, all its matter is what it’s doing" << std::endl;
  d(new std::string("take a coffee"), 20);
  std::cout << d << std::endl;
  while (d(new std::string("Patrol around"), 20))
    {
      if (!d(new std::string("Shoot some ennemies"), 50))
	d(new std::string("Run Away"), 20);
      std::cout << d << std::endl;
    }
  std::cout << d << std::endl;
  return (0);
}
*/
