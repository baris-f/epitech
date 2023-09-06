#ifndef PICTURE_H_
# define PICTURE_H_

#include <iostream>
#include <fstream>

class Picture {
 public :
  Picture();
  Picture(const Picture &);
  Picture(const std::string& file);
  ~Picture();
  Picture &	operator=(const Picture &);
 public :
  std::string data;
  bool getPictureFromFile(const std::string & file);

};

#endif /* !PICTURE_H_ */
