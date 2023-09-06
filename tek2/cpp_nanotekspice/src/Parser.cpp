#include "Parser.hpp"

namespace nts
{
  Parser::Parser()
  {
    std::cout << "created" << std::endl;
  }

  Parser::~Parser()
  {
    std::cout << "deleted" << std::endl;
  }

  void	Parser::feed(std::string const& str)
  {
    Input += str;
  }

  void	Parser::parseTree(t_ast_node&)
  {
  }

  t_ast_node*	Parser::createTree()
  {
    t_ast_node*	left = new t_ast_node();
    t_ast_node*	rigth = new t_ast_node();



    //    std::cout << Input << std::endl;

  }
}
