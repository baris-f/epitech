#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


#include "struct.hpp"


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

Endpoint &getEndpoint(int id, Data data){
  int i = 0;
  std::list<Endpoint>::iterator it = data.E.begin();
  for(Endpoint &e : data.E){
    if (e.ID == id){
      return e;
    }
  }
}

bool cacheExist(int id, Data &data){
  for(Cache c : data.C){
    if (c.ID == id){
      return true;
    }
  }
  return false;
}

Cache &getCache(int id, Data &data){
  for(Cache &c : data.C){
    if (c.ID == id){
      return c;
    }
  }
}

Data fillData(char *filename){
  Data data;
  std::ifstream file;
  std::string tmp;
  int i = -1;
  std::vector<std::string> tmpv;

  file.open (filename);


  //recuperation des infos de base
  std::getline(file, tmp);
  tmpv = split(tmp, ' ');
  data.Vmax = std::stoi(tmpv[0]);
  data.Emax = std::stoi(tmpv[1]);
  data.Rmax = std::stoi(tmpv[2]);
  data.Cmax = std::stoi(tmpv[3]);
  data.Xmax = std::stoi(tmpv[4]);

  //get video info
  std::getline(file, tmp);
  tmpv = split(tmp, ' ');
  while (++i < data.Vmax){
    data.V.push_back(Video(i, std::stoi(tmpv[i])));
  }

  //get endpoint
  i = -1;
  while (++i < data.Emax){
    std::getline(file, tmp);
    tmpv = split(tmp, ' ');
    Endpoint e(i, std::stoi(tmpv[0]));
    int nbC = std::stoi(tmpv[1]);
    int j = -1;
    while (++j < nbC) {
      std::getline(file, tmp);
      std::vector<std::string> tmpc = split(tmp, ' ');
      int id = std::stoi(tmpc[0]);
      if (cacheExist(id, data)){
	e.C.push_back(MyCache(id, std::stoi(tmpc[1]), getCache(id, data)));
      } else {
	data.C.push_back(Cache(id, data.Xmax));
	e.C.push_back(MyCache(id, std::stoi(tmpc[1]), data.C.back()));
      }
    }
    data.E.push_back(e);
  }

  //get request
  i =-1;
  while (++i < data.Rmax){
    std::getline(file, tmp);
    tmpv = split(tmp, ' ');
    data.R.push_back(Request(std::stoi(tmpv[0]), std::stoi(tmpv[1]), std::stoi(tmpv[2])));
  }

  for(Request r : data.R){
    Endpoint &e = getEndpoint(r.E_ID, data);
    e.R.push_back(r);
  }




  file.close();
  return data;
}



int main(int ac, char **av){
  fillData(av[1]);
}
