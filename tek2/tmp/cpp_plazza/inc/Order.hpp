#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

enum Information
{
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS
};

class Order {
public:
  Order(std::string nfile, Information norder);
  ~Order(){};
  const Information     &getOrder() const {return (order);};
  const std::string     &getFile() const {return (file);};
private :
  Information   order;
  std::string   file;
};

void            operator<<(std::string &, Order const &);
//std::ostream &operator>>(std::ostream &, Object const &);

#endif /* ORDER_HPP */
