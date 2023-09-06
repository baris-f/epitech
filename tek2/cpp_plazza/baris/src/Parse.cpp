//
// Parse.cpp for plazza in /home/baris_f/rendu/tek2/cpp_plazza/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Apr 29 14:21:49 2017 baris_f
// Last update Sat Apr 29 15:58:46 2017 baris_f
//

#include "Parse.hpp"

std::vector<std::string> sInformation
{
  "PHONE_NUMBER",
  "EMAIL_ADDRESS",
  "IP_ADDRESS"
};

void            Parse::cut(std::string line)
{
  std::string   cmd;
  std::string   tmp;

  std::stringstream sline (line);
  while (getline (sline, cmd, ';'))
    {
      std::stringstream command (cmd);
      while (std::getline(command, tmp, ' '))
        {
          if (tmp != "")
            {
              if (isFile(tmp) == true)
                files.push_back(tmp);
              else if (getInfo(tmp) >= 0)
                orders.push_back(tmp);
              else
                std::cout << tmp << " : Not a file or an existing order" << std::endl;
            }
        }
      sendOrders();
    }
}

void            Parse::sendOrders()
{
  for (size_t i = 0; i < files.size(); i++)
    for (size_t j = 0; j < orders.size(); j++)
      {
        Order           tmp(files[i], static_cast<Information>(getInfo(orders[j])));
        std::string     serialized;

        serialized << tmp;
        std::cout << serialized << std::endl;
      }
  files.clear();
  orders.clear();
}

bool            Parse::isFile(std::string path)
{
  std::ifstream myfile;

  myfile.open (path);
  if (myfile.is_open() == false)
    return (false);
  else
    {
      myfile.close();
      return (true);
    }
}

int             Parse::getInfo(std::string req)
{
  for (size_t i = 0; i < sInformation.size(); i++)
    {
      if (req.compare(sInformation[i]) == 0)
        return (i);
    }
  return (-1);
}
