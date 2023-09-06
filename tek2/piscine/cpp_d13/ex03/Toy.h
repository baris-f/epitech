#ifndef TOY_H_
# define TOY_H_

#include "Picture.h"

class Toy {
 public :
  enum ToyType{ BASIC_TOY, ALIEN, BUZZ, WOODY};
 public :
  Toy();
  Toy(const Toy &);
  Toy(ToyType, std::string name, std::string filename);
  virtual ~Toy();
  Toy &	operator=(const Toy &);
 protected :
  ToyType	_type;
  std::string	_name;
  Picture	_picture;
 public :
  ToyType 		getType() const;
  std::string const	getName() const;
  void			setName(std::string);
  std::string const	getAscii() const;
  bool			setAscii(std::string);
  virtual void			speak(std::string str);
};

#endif /* !TOY_H_ */
