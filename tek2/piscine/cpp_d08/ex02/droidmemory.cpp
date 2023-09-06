//
// droidmemory.cpp for  mem in /home/baris_f/rendu/tek2/cpp_d08/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 11 16:18:33 2017 baris_f
// Last update Wed Jan 11 23:27:28 2017 baris_f
//

#include "droidmemory.hh"

DroidMemory::DroidMemory()
{
  setExp(0);
  setFingerPrint(random());
}

DroidMemory::~DroidMemory(){
}

size_t	DroidMemory::getFingerPrint() const { return (_FingerPrint);};
void	DroidMemory::setFingerPrint(size_t FingerPrint){ _FingerPrint = FingerPrint;};
size_t	DroidMemory::getExp() const { return(_Exp);};
void	DroidMemory::setExp(size_t Exp){ _Exp = Exp;};

DroidMemory  &DroidMemory::operator<<(DroidMemory const &other)
{
  setExp(getExp() + other.getExp());
  setFingerPrint(getFingerPrint() xor other.getFingerPrint());
  return (*this);
}

DroidMemory  &DroidMemory::operator>>(DroidMemory &other)
{
  other.setExp(getExp() + other.getExp());
  other.setFingerPrint(getFingerPrint() xor other.getFingerPrint());
  return (other);
}

DroidMemory	&DroidMemory::operator+=(DroidMemory const &other){
  setExp(other.getExp() + getExp());
  setFingerPrint(getFingerPrint() xor other.getFingerPrint());
  return (*this);
}

DroidMemory	&DroidMemory::operator+=(size_t const other){
  setExp(getExp() + other);
  setFingerPrint(getFingerPrint() xor other);
  return(*this);
}

DroidMemory	DroidMemory::operator+(DroidMemory const &other) const
{
  DroidMemory	*dmem = new DroidMemory;

  dmem->setExp(getExp() + other.getExp());
  dmem->setFingerPrint(getFingerPrint() xor other.getFingerPrint());
  return(*dmem);
}

bool		DroidMemory::operator==(DroidMemory const &other) const
{
  if (getExp() == other.getExp() && getFingerPrint() == other.getFingerPrint())
    return (true);
  return (false);
}

bool		DroidMemory::operator!=(DroidMemory const &other) const
{
  if (getExp() == other.getExp() && getFingerPrint() == other.getFingerPrint())
    return (false);
  return (true);
}

bool		DroidMemory::operator<(DroidMemory const &other) const
{
  if (getExp() < other.getExp())
    return (true);
  return (false);
}

bool		DroidMemory::operator<(size_t const other) const
{
  if (getExp() < other)
    return (true);
  return (false);
}

bool		DroidMemory::operator>(DroidMemory const &other) const
{
  if (getExp() > other.getExp())
    return (true);
  return (false);
}

bool		DroidMemory::operator>(size_t const other) const
{
  if (getExp() > other)
    return (true);
  return (false);
}

bool		DroidMemory::operator<=(DroidMemory const &other) const
{
  if (getExp() <= other.getExp())
    return (true);
  return (false);
}

bool		DroidMemory::operator<=(size_t const other) const
{
  if (getExp() <= other)
    return (true);
  return (false);
}

bool		DroidMemory::operator>=(DroidMemory const &other) const
{
  if (getExp() >= other.getExp())
    return (true);
  return (false);
}

bool		DroidMemory::operator>=(size_t const other) const
{
  if (getExp() >= other)
    return (true);
  return (false);
}

std::ostream&   operator<<(std::ostream& os, DroidMemory const& droid)
{
  os << "DroidMemory '" << droid.getFingerPrint() << "', " << droid.getExp();
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
}
*/
