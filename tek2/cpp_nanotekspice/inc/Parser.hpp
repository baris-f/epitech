#ifndef PARSER
#define PARSER

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "IParser.hpp"

namespace nts
{
  class Parser : IParser
  {
  public:
    Parser();
    ~Parser();

    void	feed(std::string const&);
    void	parseTree(t_ast_node&);
    t_ast_node*	createTree();

  private:
    std::string	Input;
  };
};
#endif
