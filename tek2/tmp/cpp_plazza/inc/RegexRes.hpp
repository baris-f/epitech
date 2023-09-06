#ifndef	__REGEXRES_HPP__
#define __REGEXRES_HPP__

#include <iostream>
#include <thread> 	
#include <regex>
#include <vector>

enum Information {
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS
};

class RegexRes {
public:
  RegexRes();
  RegexRes(const std::vector<std::regex> &regex);
  virtual	~RegexRes();
  void		resolve();
  void		addRegex(const std::string &regx);
  void		addSerial(const std::string &ser);
  const std::string	&getResult() const;
private:
  std::vector<std::regex>	regex;
  std::string			serial;
  std::ifstream			fd;
  Information			req;
  std::string			res;
};

void	operator>>(const std::string &serial, RegexRes &reg);
void	operator<<(std::string &result, const RegexRes &reg); 

#endif
