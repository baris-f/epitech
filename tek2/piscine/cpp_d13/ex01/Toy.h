#ifndef TOY_H_
# define TOY_H_

#include "Picture.h"

class Toy {
 public :
  enum ToyType{ BASIC_TOY, ALIEN};
 public :
  Toy();
  Toy(const Toy &);
  Toy(ToyType, std::string, std::string);
  ~Toy();
  Toy &	operator=(const Toy &);
 private :
  ToyType	_type;
  std::string	_name;
  Picture	_picture;
 public :
  ToyType 		getType() const;
  std::string const	getName() const;
  void			setName(std::string);
  std::string const	getAscii() const;
  bool			setAscii(std::string);
};

#endif /* !TOY_H_ */
