#include "Parser.hpp"

using namespace nts;

int main(int ac, char **av)
{
  (void)ac;
  std::ifstream		file(av[1]);
  std::stringstream	buff;
  Parser		parser;
  t_ast_node*		ast;

  buff << file.rdbuf();
  //std::cout << buff.str() << std::endl;
  parser.feed(buff.str());
  ast = parser.createTree();
  //parser.parseTree(*ast);
  return (0);
}
