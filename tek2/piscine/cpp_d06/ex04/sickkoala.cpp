/*
** sickkoala.c for sickkoala in /home/baris_f/rendu/tek2/cpp_d06/ex02
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Jan  9 10:56:49 2017 baris_f
// Last update Mon Jan  9 19:40:13 2017 baris_f
*/

#include "sickkoala.h"

SickKoala::SickKoala(std::string newname)
{
  name = newname;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr. " << name << ": Kreooogg!! Je suis gueriiii!" << std::endl;
}

void	SickKoala::poke()
{
  std::cout << "Mr. " << name << ": Gooeeeeerrk!! :'(" << std::endl;
}

bool	SickKoala::takeDrug(std::string drug)
{
  std::string m(drug);

  std::transform(m.begin(), m.end(), m.begin(), ::tolower);
  if (m == "mars")
    std::cout << "Mr. " << name << ": Mars, et ca kreog!" << std::endl;
  else if (drug == "Buronzand")
    std::cout << "Mr. " << name << ": Et la fatigue a fait son temps!" << std::endl;
  else
    {
      std::cout << "Mr. " << name << ": Goerkreog!" << std::endl;
      return (false);
    }
  return (true);
}

void	SickKoala::overDrive(std::string str)
{
  size_t	pos;

  while ((pos = str.find("Kreog!", 0)) != std::string::npos)
      str.replace(pos, 6, "1337!");
  std::cout << "Mr. " << name << ": " <<  str << std::endl;
}

std::string	SickKoala::getName()
{
  return (name);
}

/*
int             main()
{
  SickKoala     jojo("jojo");

  jojo.poke();
  jojo.takeDrug("mars");
  jojo.takeDrug("maRs");
  jojo.takeDrug("MaRs");
  jojo.takeDrug("MARS");
  jojo.takeDrug("yolo");
  jojo.takeDrug("Buronzand");
  jojo.overDrive("Je vole Kreog! comme un petit oiseau Kreog! Kreog!");
  return (0);
}
*/
