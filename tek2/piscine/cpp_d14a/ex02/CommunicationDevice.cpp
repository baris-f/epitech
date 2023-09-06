
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
try : _api(input, output)
{
}
catch    (std::runtime_error const &error) {
  std::cout << "Error: " << error.what() << std::endl;
 }

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
  try{  for (size_t i = 0; i < nbUsers; ++i)
        _api.addUser(users[i]);
    _api.startMission(missionName);
  } catch (std::logic_error const &error)
    {
      std::cout << "LogicError: " << error.what() << std::endl;
    }
  catch (std::runtime_error const &error)
    {
      std::cout << "RuntimeError: "<< error.what() << std::endl;
    }
  catch (std::exception const &error)
    {
      std::cout << "Error: "<< error.what() << std::endl;
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
  try {
    _api.sendMessage(user, message);
  } catch (std::invalid_argument const &arg) {
        std::cout << arg.what() << std::endl;
  }
  catch (std::runtime_error const &arg)
    {
      std::cout << arg.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
  try {
    _api.receiveMessage(user, message);
  } catch (std::invalid_argument const & error)
    {
      std::cout << error.what() << std::endl;
      message = "INVALID MESSAGE";
    }
  catch (std::runtime_error const & error)
    {
      std::cout << error.what() << std::endl;
      message = "INVALID MESSAGE";
    }
}
