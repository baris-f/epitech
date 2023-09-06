//
// koaladoctor.cpp for doctor in /home/baris_f/rendu/tek2/cpp_d06/ex04
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan  9 14:51:52 2017 baris_f
// Last update Mon Jan  9 22:57:43 2017 baris_f
//

#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string newname)
{
  status = false;
  name = newname;
  std::cout << "Dr. " << name << ": Je suis le Dr." << name << "! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{

}

void	KoalaDoctor::diagnose(SickKoala* koala)
{
  std::string	kname = koala->getName();
  std::string	medtab[] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'Eucalyptus"};
  std::string	med;
  std::string	filename = kname + ".report";
  std::ofstream outfile (filename.c_str());

  std::cout << "Dr. " << name << ": Alors, qu'est-ce qui vous goerk, Mr." << kname << " ?" << std::endl;
  koala->poke();
  med = medtab[random() % 5];
  if (outfile.is_open())
    outfile << med;
}

void    KoalaDoctor::timeCheck()
{
  status = !status;
  if (status)
    std::cout << "Dr." << name << ": Je commence le travail!" << std::endl;
  else
    std::cout << "Dr." << name << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
}
/*
int     main()
{
  KoalaDoctor   doc("toto");
  SickKoala     pat("titi");

  doc.timeCheck();
  doc.diagnose(&pat);
  return (0);
}
*/
