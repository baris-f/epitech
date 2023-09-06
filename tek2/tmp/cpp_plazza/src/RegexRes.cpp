#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>

#include "RegexRes.hpp"

RegexRes::RegexRes()
{
  addRegex("[0][1-9][ ]?[0-9]{2}[ ]?[0-9]{2}[ ]?[0-9]{2}[ ]?[0-9]{2}");
  addRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  addRegex("\\d{1,3}(\\.\\d{1,3}){3}");
}

RegexRes::RegexRes(const std::vector<std::regex> &regex)
  : regex(regex)
{}

RegexRes::~RegexRes()
{}

void	RegexRes::addRegex(const std::string &regx)
{
  std::regex r (regx);
  
  regex.push_back(r);
}

void	RegexRes::addSerial(const std::string &ser)
{
  serial = ser;
}

const std::string&	RegexRes::getResult() const
{
  return res;
}

void	RegexRes::resolve()
{
  req = static_cast<Information>(std::stoi(serial));
  fd.open(serial.substr(serial.find("|") + 1));
  std::string str((std::istreambuf_iterator<char>(fd)),
                  std::istreambuf_iterator<char>());
  std::regex_iterator<std::string::iterator> rit ( str.begin(), str.end(), regex[req]);
  std::regex_iterator<std::string::iterator> rend;
  for (;rit != rend; ++rit)
    res += rit->str() + "\n";
}

void operator>>(const std::string &serial, RegexRes &reg)
{
  reg.addSerial(serial);
}

void operator<<(std::string &result, const RegexRes &reg)
{
  result = reg.getResult();
}

void	DoRegex(std::string serial)
{
  RegexRes regex;
  std::string result;
  
  serial >> regex;
  regex.resolve();
  result << regex;
  std::cout << result;
}