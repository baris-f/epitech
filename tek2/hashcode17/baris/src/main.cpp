//
// main.cpp for hascode17 in /home/baris_f/rendu/tek2/hashcode17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Feb 23 19:24:15 2017 baris_f
// Last update Sat Feb 25 16:40:02 2017 baris_f
//

#include <ctime>
#include "struct.hpp"

void	calc_saved(Data &data)
{
  std::cout << "starting to calc time saved..." << std::endl;
  for (Video *V : data.V)
    {
      for (Cache *C : data.C)
	{
	  V->SetSaved(C->ID, 0);
	  for (Endpoint *E : data.E)
	    {
	      if (E->hasLink(C->ID))
		{
		  if (E->getLatency(C->ID) < E->latency)
		    V->SetSaved(C->ID, V->getSaved(C->ID) + (E->latency - E->getLatency(C->ID)) * E->getRequest(V->ID));
		}
	    }
	}
    }
  std::cout << "calc ";
}

int	addToCache(Data &data, int ID, Video V)
{
  for (Cache *C : data.C)
    {
      if (C->ID == ID)
	{
	  if (C->getSizeLeft() < V.size)
	    return (-1);
	  C->V.push_back(V);
	  return (0);
	}
    }
  return (-1);
}

Video *getVideo(int id, Data data);

void	insertSaved(std::vector<Saved*> &best, Saved *S)
{
  int	idx;
  std::vector<Saved*>::iterator it = best.begin();

  idx = best.size() - 1;
  if (S && (idx+1 == 0 || S->saved <= best[idx]->saved)) {
    best.push_back(S);
  } else{
    while (--idx > 0) //&& S->saved > best[idx]->saved)
    {
	if (S->saved <= best[idx]->saved)
	  {
	    best.insert(it + idx + 1, S);
	    return ;
	  }
    }
    best.insert(it, S);
  }
}

int    	getBestSaved(Data &data)
{
  //  bool	worked = false;
  /*  int	cBest = 0;
      Video *cBVideo;
      Saved	*cBSaved;*/
  std::vector<Saved*>	best;

  std::cout << "start to sort..." << std::endl;
  for (Video *V : data.V)
    {
      for (Saved &S : V->S)
	{
	  /*	  if (S.saved > cBest)
		  {
		  worked = true;
		  cBSaved = &S;
		  cBVideo = V;
		  cBest = S.saved;
		  }*/
	  if (S.saved > 0)
	    insertSaved(best, &S);
	}
    }
  std::cout << "sort done" << std::endl;
  //if (!worked)
  //    return (-1);
  //  cBSaved->saved = 0;
  std::cout << "adding video to caches..." << std::endl;
  for (unsigned int i = 0; i < best.size(); i++)
    addToCache(data, best[i]->ID, *(getVideo(best[i]->vID, data)));
  std::cout << best.size() << " saved"<< std::endl;
  return (0);
}

void	fillData(char *caca, Data&);
int	writeRendu(Data &data);

int	main(int ac, char **av)
{
  Data	data;
  int	dtime = time(NULL);

  if (ac != 2)
    return 0;
  std::cout << "starting filling data..." << std::endl;
  fillData(av[1], data);
  std::cout << "done\t" << time(NULL) - dtime << std::endl;
  dtime = time(NULL);
  calc_saved(data);
  std::cout << "done\t" << time(NULL) - dtime << std::endl;
  dtime = time(NULL);
  getBestSaved(data);
  std::cout << "done\t" << time(NULL) - dtime << std::endl;
  dtime = time(NULL);
  writeRendu(data);
  std::cout << "write done\t" << time(NULL) - dtime << std::endl;
  return (0);
}
