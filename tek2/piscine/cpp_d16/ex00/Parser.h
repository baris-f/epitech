#ifndef PARSER_H_
# define PARSER_H_

/*!class Stack {
 public :
  Stack();
  ~Stack();

};*/

#include <iostream>
#include <stack>

class Parser {
 public :
  Parser();
  ~Parser();
 private :
  std::stack<char>	operat;
  std::stack<int>	operand;
 public :
  void	feed(const std::string &);
  int	result() const;
  void	reset();
};

#endif /* !PARSER_H_ */
