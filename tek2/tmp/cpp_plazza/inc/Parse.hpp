
#ifndef PARSE_H_
#define PARSE_H_

#include "Order.hpp"

class Parse
{
public:
  Parse(){};
  ~Parse(){};
  void cut(std::string);
  void sendOrders();
  bool isFile(std::string);
  int getInfo(std::string);
  std::vector<std::string> &getSerials(){ return (serials);  };
  void cleanSerials();
  void affSerials();

private:
  std::vector<std::string> serials;
  std::vector<std::string> files;
  std::vector<std::string> orders;
};

void DoRegex(std::string);

#endif /* !PARSE_H_ */

//test.txt PHONE_NUMBER;test.txt IP_ADDRESS