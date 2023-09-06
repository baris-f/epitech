/*
** Skat.c for skat in /home/baris_f/rendu/tek2/cpp_d07a
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Tue Jan 10 17:02:01 2017 baris_f
// Last update Wed Jan 11 08:55:31 2017 baris_f
*/

#include "Skat.h"

Skat::Skat(std::string const& name, int stimPaks)
{
  _name = name;
  _stimPaks = stimPaks;
}

Skat::~Skat()
{

}

const std::string	&Skat::name(){
  return (_name);
}

int&		Skat::stimPaks(){
  return (_stimPaks);
}

void	Skat::shareStimPaks(int number, int& stock)
{
  if (number > _stimPaks)
    {
      std::cout << "Don't be greedy" << std::endl;
      return ;
    }
  std::cout << "Keep the change." << std::endl;
  _stimPaks -= number;
  stock += number;
}

void	Skat::addStimPaks(unsigned int number)
{
  if (number == 0)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  _stimPaks += number;
}

void	Skat::useStimPaks()
{
  if (_stimPaks <= 0)
    {
      std::cout << "Mediiiiiic" << std::endl;
      return ;
    }
  _stimPaks--;
  std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void	Skat::status()
{
  std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir !" << std::endl;
}
/*
int main()
{
  Skat  s("Junior", 5);
  Skat  t("Senior", 10);
  Skat  u;

  s.status();
  s.useStimPaks();

  s.status();
  s.addStimPaks(5);

  std::cout << std::endl;

  s.status();
  t.status();
  s.shareStimPaks(2, t.stimPaks());

  std::cout << std::endl;

  s.status();
  t.status();

  u.status();
  return 0;
}
*/
