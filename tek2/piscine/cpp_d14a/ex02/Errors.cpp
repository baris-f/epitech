//
// Errors.cpp for errors in /home/baris_f/rendu/tek2/cpp_d14a/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 15:17:13 2017 baris_f
// Last update Wed Jan 18 09:10:39 2017 baris_f
//

#include "Errors.hpp"

NasaError::NasaError(std::string const &message,
		     std::string const &component)
{
  _message = message;
  _component = component;
}

std::string const &	NasaError::getComponent() const {return (_component);}

const char*	NasaError::what() const throw()
{
  return (_message.c_str());
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{

}

LifeCriticalError::LifeCriticalError(std::string const &message,
				     std::string const &component) : NasaError(message, component)
{

}

UserError::UserError(std::string const &message,
		     std::string const &component) : NasaError(message, component)
{

}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{

}
