/*
** writeToFile.c for hascode17 in /home/baris_f/rendu/tek2/hashcode17/baris
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Feb 23 21:28:14 2017 baris_f
// Last update Thu Feb 23 23:16:21 2017 baris_f
*/

#include "struct.hpp"

int	getNbCache(Data &data)
{
  int	nb = 0;

  for (Cache *C : data.C)
    {
      if (C->V.size() > 0)
	nb++;
    }
  return (nb);
}

void	describeCaches(Data &data, std::ofstream &file)
{
  for (Cache *C : data.C)
    {
      if (C->V.size() > 0)
	{
	  file << C->ID;
	  for (Video V : C->V)
	    {
	      file << " " << V.ID;
	    }
	  file << std::endl;
	}
    }
}

int	writeRendu(Data &data)
{
  std::ofstream	file;
  file.open("rendu.txt", std::ios::out);
  if (file.bad())
    return -1;
  file << getNbCache(data) << std::endl;
  describeCaches(data, file);
  file.close();
  return 0;
}
