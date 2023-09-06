//
// main.cpp for  in /home/fus/taff/cpp_santa/ex4/src
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Fri Jan 13 23:41:02 2017 Gaspard Thirion
// Last update Sun Jan 15 05:19:44 2017 baris_f
//

#include "Box.hh"
#include "Teddy.hh"
#include "TablePePeNoel.hh"
#include "ConveyorBeltPePeNoel.hh"
#include "ElfOfPePeNoel.hh"

ITable *createTable()
{
  return (ITable *)new TablePePeNoel();
}

IConveyorBelt *createConveyorBelt()
{
  return (IConveyorBelt *)new ConveyorBeltPePeNoel();
}

void	aff(TablePePeNoel *table)
{
  std::cout << std::endl;
  std::cout << "size :" << table->getSize() << std::endl;
  std::string*  tab = table->Look();
  int   i = -1;

  while (tab[++i] != "")
    std::cout << tab[i] << std::endl;
  std::cout << std::endl;
}

int main()
{

  ElfOfPePeNoel elf;

  elf.wrapAGift();
  elf.wrapAGift();
  elf.wrapAGift();
  elf.wrapAGift();
  return (0);
}
