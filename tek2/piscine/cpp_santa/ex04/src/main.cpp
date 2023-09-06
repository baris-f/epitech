//
// main.cpp for  in /home/fus/taff/cpp_santa/ex4/src
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Fri Jan 13 23:41:02 2017 Gaspard Thirion
// Last update Sun Jan 15 02:34:00 2017 baris_f
//

#include "Box.hh"
#include "Teddy.hh"
#include "TablePePeNoel.hh"
#include "ConveyorBeltPePeNoel.hh"

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
  TablePePeNoel	*table = (TablePePeNoel *)createTable();
  ConveyorBeltPePeNoel *convoy = (ConveyorBeltPePeNoel *)createConveyorBelt();
  Wrap		*wrap;

  table->Put(new Teddy("teddy"));
  table->Put(new Teddy("teddy"));
  table->Put(new Teddy("teddy"));
  table->Put(new Teddy("teddy"));
  table->Put(new Teddy("teddy"));
  table->Put(new Teddy("teddy"));
  table->Put(new Box("teddy"));
  table->Put(new Box("teddy"));
  table->Put(new Box("teddy"));


  aff(table);

  convoy->in();
  std::cout << convoy->look() << std::endl;
  wrap = convoy->take();
  convoy->in();
  std::cout << convoy->look() << std::endl;
  table->Put(wrap);

  aff(table);
  table->Put(new Box("teddy"));

  return (0);
}
