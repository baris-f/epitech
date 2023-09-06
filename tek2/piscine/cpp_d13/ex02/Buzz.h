#ifndef BUZZ_H_
# define BUZZ_H_

#include "Toy.h"

class Buzz : public Toy {
 public :
  Buzz(std::string, std::string filename = "buzz.txt");
  ~Buzz();
};

#endif /* !BUZZ_H_ */
