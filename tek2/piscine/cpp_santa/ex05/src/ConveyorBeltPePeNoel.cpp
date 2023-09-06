#include "ConveyorBeltPePeNoel.hh"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() :
  _object(NULL), _lastIsBox(false)
{
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{
  if (_object)
    delete _object;
}

void		ConveyorBeltPePeNoel::in()
{
  if (!_object)
    {
      if (_lastIsBox)
	{
	  _object = new GiftPaper();
	  _lastIsBox = false;
	}
      else
	{
	  _object = new Box();
	  _lastIsBox = true;
	}
    }
  else
    std::cerr << "Button 'IN' doesn't work, there's already an object" << std::endl;
}

void		ConveyorBeltPePeNoel::out()
{
  if (_object)
    {
      //delete _object;
      std::cout << "Object send to Santa :)" << std::endl;
    }
  else
    std::cerr << "Button 'OUT' doesn't work, there is no object to send to Santa :(" << std::endl;
}

Wrap *	ConveyorBeltPePeNoel::take(){
  Wrap *tmp;
  if (_object){
    tmp = _object;
    _object = NULL;
    return tmp;
  } else
    std::cerr << "There is nothing to take :(" << std::endl;
  return NULL;
}

void		ConveyorBeltPePeNoel::put(Wrap* new_object)
{
  if (new_object){
    if (!_object)
      _object = new_object;
    else
      std::cerr << "Object can't be put on the conveyor belt ! There's already an object" << std::endl;
  }
}

std::string	ConveyorBeltPePeNoel::look()
{
  if (_object)
    return (_object->getType());
  else
    return NULL;
}
