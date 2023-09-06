#ifndef STRUCT_H_
# define STRUCT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

class Saved {
public:
  int ID;
  int vID;
  int saved;

  Saved(int _ID, int _saved, int V_ID){
    ID = _ID;
    saved = _saved;
    vID = V_ID;
  }
};

class Video {
public:
  int ID;
  int size;
  std::list<Saved> S;

  Video(int _ID, int _size){
    ID = _ID;
    size = _size;
  }

  void SetSaved(int id, int svd){
    for(Saved &s : S){
      if (s.ID == id){
	s.saved = svd;
	return;
      }
    }
    S.push_back(Saved(id, svd, ID));
  }

  int getSaved(int id){
    for(Saved s : S){
      if (s.ID == id){
	return s.saved;
      }
    }
    return 0;
  }

};

class Cache {
public:
  int ID;
  std::list<Video> V;
  int maxSize;

  Cache(int _ID, int s){
    ID = _ID;
    maxSize = s;
  }

  Cache(const Cache &o){
    ID = o.ID;
    maxSize = o.maxSize;
  }

  int getSizeLeft(){
    int size = 0;
    for(Video v : V){
      size += v.size;
    }
    return maxSize - size;
  }
};

class MyCache {
public:
  int ID;
  int latency;
  Cache *C;

  MyCache(int _ID, int _latency, Cache *_c) : C(_c) {
    ID = _ID;
    latency = _latency;
  }
};

class Request {
public:
  int V_ID;
  int E_ID;
  int nbRequest;

  Request(int ID, int _E_ID, int _nbR){
    V_ID = ID;
    E_ID = _E_ID;
    nbRequest = _nbR;
  }
};


class Endpoint {
public:
  int ID;
  int latency;
  std::list<MyCache> C;
  std::list<Request> R;

  Endpoint(int _ID, int _latency){
    ID = _ID;
    latency = _latency;
  }

  bool hasLink(int id){
    for(MyCache c : C){
      if (c.ID == id)
	return true;
    }
    return false;
  }

  int getLatency(int id){
    for(MyCache c : C){
      if (c.ID == id)
	return c.latency;
    }
    return latency;
  }

  int getRequest(int id){
    for(Request r : R){
      if (r.V_ID == id){
	return r.nbRequest;
      }
    }
    return 0;
  }
};

struct Data {
  int Vmax;
  int Emax;
  int Rmax;
  int Cmax;
  int Xmax;

  std::list<Video *> V;
  std::list<Endpoint *> E;
  std::list<Cache *> C;
};

#endif /* !STRUCT_H_ */
