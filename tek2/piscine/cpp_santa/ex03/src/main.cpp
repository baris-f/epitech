//
// main.cpp for main in /home/baris_f/rendu/tek2/cpp_santa/ex03/src
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 14 00:56:04 2017 baris_f
// Last update Sun Jan 15 02:00:16 2017 baris_f
//

#include "Box.hh"
#include "GiftPaper.hh"
#include "Teddy.hh"

int	findObj(std::string type, Object **tab, int size)
{
  int	i;

  for(i = 0; (*tab[i]).getType() != type && i < size - 1; i++)
    if (i == 3)
      return (-1);
  return (i);
}

Object *MyUnitTests(Object **tab)
{
  int		tmp = 0;

  if ((tmp = findObj("Toy", tab , 3)) == -1)
    {
      std::cerr << "There is no toy to wrap !" << std::endl;
      return (NULL);
    }
  Toy	*toy = new Toy((const Toy &)*tab[tmp]);
  if ((tmp = findObj("Box", tab , 3)) == -1)
    {
      std::cerr << "There is no box to wrap !" << std::endl;
      return (NULL);
    }
  Box *box = new Box((Box const &)*tab[tmp]);
  if ((tmp = findObj("GiftPaper", tab , 3)) == -1)
    {
      std::cerr << "There is no giftpaper to wrap !" << std::endl;
      return (NULL);
    }
  GiftPaper *gp = new GiftPaper((GiftPaper const &)*tab[tmp]);

  box->openMe();
  box->wrapMeThat(toy);
  box->closeMe();
  gp->wrapMeThat(box);

  return (gp);
}

int main()
{
  Object **elem = new Object*[3];
  GiftPaper *gp = new GiftPaper("gift2");
  Box	*box = new Box();
  Teddy	*ted = new Teddy("Bisounours");
  Object	*gift;

  elem[0] = gp;
  elem[1] = box;
  elem[2] = ted;
  gift = MyUnitTests(elem);
  if (gift)
    std::cout << gift->getName() << std::endl;
  return (0);
}
