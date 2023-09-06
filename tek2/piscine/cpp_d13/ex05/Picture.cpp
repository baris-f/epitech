//
// Picture.cpp for picture in /home/baris_f/rendu/tek2/cpp_d13/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan 16 09:52:43 2017 baris_f
// Last update Mon Jan 16 13:19:33 2017 baris_f
//

#include "Picture.h"

Picture::Picture()
{
  data = "";
}

Picture::Picture(const Picture & other)
{
  data = other.data;
}

Picture::Picture(const std::string & file)
{
  getPictureFromFile(file);
}

Picture::~Picture()
{

}

Picture &	Picture::operator=(const Picture & other)
{
  data = other.data;
  return (*this);
}

bool	Picture::getPictureFromFile(const std::string& file)
{
  std::ifstream myfile(file.c_str());
  char	c;

  if (myfile.is_open())
    {
      while (myfile.get(c))
	data += c;
      myfile.close();
      return(true);
    }
  data = "ERROR";
  return (false);
}
