/*
** koalanurse.c for nurse in /home/baris_f/rendu/tek2/cpp_d06/ex03
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Jan  9 13:54:24 2017 baris_f
// Last update Mon Jan  9 17:13:27 2017 baris_f
*/

#include "koalanurse.h"

KoalaNurse::KoalaNurse(int newID)
{
  status = false;
  ID = newID;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << ID << ": Enfin un peu de repos!" << std::endl;
}

void	KoalaNurse::giveDrug(std::string drug, SickKoala* koala)
{
  koala->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string name)
{
  std::ifstream	myfile(name.c_str());
  std::string	drug;

  if (name.find(".report", name.length() - 8) == std::string::npos)
    return ("");
  //  myfile.open (name);
  if (myfile.is_open())
    {
      std::getline (myfile, drug);
      std::cout << "Nurse " << ID << ": Kreog! Il faut donner un " << drug << " a Mr." << name.substr(0, name.length() - 7) << "!" << std::endl;
      return (drug);
    }
  return ("");
}

void	KoalaNurse::timeCheck()
{
  status = !status;
  if (status)
    std::cout << "Nurse " << ID << ": Je commence le travail!" << std::endl;
  else
    std::cout << "Nurse " << ID << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
}

int	KoalaNurse::getID()
{
  return (ID);
}

/*
int     main()
{
  SickKoala     patient("jojo");
  KoalaNurse    nurse(3);

  nurse.timeCheck();
  nurse.giveDrug(nurse.readReport("jojo.report"), &patient);
  return (0);
  }*/
