#ifndef PARSE_H_
# define PARSE_H_

#include "Order.hpp"

class Parse {
public :
  Parse(){};
  ~Parse(){};
  void          cut(std::string);
  void  sendOrders();
  bool  isFile(std::string);
  int   getInfo(std::string);
private :
  std::vector<std::string> files;
  std::vector<std::string> orders;
};


#endif /* !PARSE_H_ */
