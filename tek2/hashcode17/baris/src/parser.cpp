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

Video *getVideo(int id, Data data){
  for(Video *v : data.V){
    if (v->ID == id){
      return v;
    }
  }
}

Endpoint *getEndpoint(int id, Data data){
  for(Endpoint *e : data.E){
    if (e->ID == id){
      return e;
    }
  }
}

bool cacheExist(int id, Data &data){
  for(Cache *c : data.C){
    if (c->ID == id){
      return true;
    }
  }
  return false;
}

Cache *getCache(int id, Data &data){
  for(Cache *c : data.C){
    if (c->ID == id){
      return c;
    }
  }
}


std::string my_getline(std::vector<std::string> &v){
  static int i = -1;
  return v[++i];
}

void	fillData(char *filename, Data &data){
  std::ifstream file;
  std::stringstream stream;
  std::string stream_str;
  std::vector<std::string> whole_file;
  int i = -1;
  std::vector<std::string> tmpv;
  size_t dtime = time(NULL);

  file.open (filename);
  stream << file.rdbuf();
  file.close();
  stream_str = stream.str();
  whole_file = split(stream_str, '\n');

  //recuperation des infos de base
  tmpv = split(my_getline(whole_file), ' ');
  data.Vmax = std::stoi(tmpv[0]);
  data.Emax = std::stoi(tmpv[1]);
  data.Rmax = std::stoi(tmpv[2]);
  data.Cmax = std::stoi(tmpv[3]);
  data.Xmax = std::stoi(tmpv[4]);
  //get video info
  tmpv = split(my_getline(whole_file), ' ');
  while (++i < data.Vmax){
    data.V.push_back(new Video(i, std::stoi(tmpv[i])));
  }

  //get endpoint
  i = -1;
  while (++i < data.Emax){
    tmpv = split(my_getline(whole_file), ' ');
    Endpoint *e = new Endpoint(i, std::stoi(tmpv[0]));
    int nbC = std::stoi(tmpv[1]);
    int j = -1;
    while (++j < nbC) {
      std::vector<std::string> tmpc = split(my_getline(whole_file), ' ');
      int id = std::stoi(tmpc[0]);
      if (cacheExist(id, data)){
	e->C.push_back(MyCache(id, std::stoi(tmpc[1]), getCache(id, data)));
      } else {
	data.C.push_back(new Cache(id, data.Xmax));
	e->C.push_back(MyCache(id, std::stoi(tmpc[1]), data.C.back()));
      }
    }
    data.E.push_back(e);
  }


  //get request
  i =-1;
  while (++i < data.Rmax){
    tmpv = split(my_getline(whole_file), ' ');
    Request r(std::stoi(tmpv[0]), std::stoi(tmpv[1]), std::stoi(tmpv[2]));
    Endpoint *e = getEndpoint(r.E_ID, data);
    e->R.push_back(r);
  }
}
