#ifndef KOALABOT_H_
# define KOALABOT_H_

#include <iostream>

#include "Parts.h"

class	KoalaBot {
 public :
  KoalaBot(std::string serial = "Bob-01");
  ~KoalaBot();
 private :
  Arms	_arm;
  Legs	_leg;
  Head	_head;
  std::string	_serial;
 public :
  void	setParts(const Arms&);
  void	setParts(const Legs&);
  void	setParts(const Head&);
  void	swapParts(Arms&);
  void	swapParts(Legs&);
  void	swapParts(Head&);
  void	informations() const;
  bool	status() const;
};

#endif /* !KOALABOT_H_ */
