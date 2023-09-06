#ifndef SKAT_H_
# define SKAT_H_

#include <iostream>

class Skat
{
 public:
  Skat(std::string const& name = "bob", int stimPaks = 15);
  ~Skat();

 public:
  int& stimPaks();
  const std::string& name();

 public:
  void shareStimPaks(int number, int& stock);
  void addStimPaks(unsigned int number);
  void useStimPaks();

 public:
  void status();
  int		_stimPaks;

 private:
  std::string	_name;
};

#endif /* !SKAT_H_ */
