#ifndef WOODY_H_
# define WOODY_H_

#include "Toy.h"

class Woody : public Toy {
 public :
  Woody(std::string, std::string filename = "woody.txt");
  ~Woody();

  virtual void	speak(std::string);
};

#endif /* !WOODY_H_ */
