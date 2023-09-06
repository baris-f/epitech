#ifndef TOY_H_
# define TOY_H_

#include "Picture.h"

class Toy {
 public :
  class Error {
  public :
    enum ErrorType{ UNKNOWN, PICTURE, SPEAK};

    Error();
    ~Error();

    ErrorType	type;
    std::string	_what;
    std::string	_where;
    std::string	&what();
    std::string &where();
  };
 public :
  enum ToyType{ BASIC_TOY, ALIEN, BUZZ, WOODY};
 public :
  Toy();
  Toy(const Toy &);
  Toy(ToyType, std::string name, std::string filename);
  virtual ~Toy();
  Toy &	operator=(const Toy &);
  Error	error;
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
  void			setAsciiStr(std::string);
  virtual void		speak(std::string str);
  virtual bool		speak_es(std::string str);
  Error &		getLastError();
};

std::ostream &	operator<<(std::ostream & os, const Toy &);
Toy &	operator<<(Toy &, std::string);

#endif /* !TOY_H_ */
