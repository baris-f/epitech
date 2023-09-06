#ifndef PART_H_
# define PART_H_

#include <iostream>

class	Arms
{
 public :
  Arms(std::string serial = "A-01", bool functionnal = true);
  ~Arms();
 private :
  std::string	_serial;
  bool		_functionnal;
 public :
  bool		isFunctionnal() const;
  std::string	serial() const;
  void		informations() const;
};

class	Legs
{
 public :
  Legs(std::string serial = "L-01", bool functionnal = true);
  ~Legs();
 private :
  std::string	_serial;
  bool		_functionnal;
 public :
  bool		isFunctionnal() const;
  std::string	serial() const;
  void		informations() const;
};

class	Head
{
 public :
  Head(std::string serial = "H-01", bool functionnal = true);
  ~Head();
 private :
  std::string	_serial;
  bool		_functionnal;
 public :
  bool		isFunctionnal() const;
  std::string	serial() const;
  void		informations() const;
};

#endif /* !PART_H_ */
