#include <iostream>
#include "ElfOfPePeNoel.hh"

ElfOfPePeNoel::ElfOfPePeNoel(){
  _Table = new TablePePeNoel();
  _Convoyer = new ConveyorBeltPePeNoel();
  _LeftHand = NULL;
  _RightHand = NULL;
}

ElfOfPePeNoel::ElfOfPePeNoel(ElfOfPePeNoel const &other){
  _Table = other._Table;
}

ElfOfPePeNoel::~ElfOfPePeNoel(){
  if (_Table)
    delete _Table;
}

ElfOfPePeNoel &ElfOfPePeNoel::operator=(ElfOfPePeNoel const &other){
  if (this != &other){
    if (_Table)
      delete _Table;
    _Table = other._Table;
  }
  return *this;
}

void	 ElfOfPePeNoel::wrapThat(Wrap *wrap, Object *obj){

  wrap->wrapMeThat(obj);
  std::cout << "tuuuut tuuut tuut" << std::endl;
  return ;
}

void	ElfOfPePeNoel::takeInWrap(Wrap *wrap){
  if (!wrap)
    return ;
  wrap->openMe();
  if (wrap->getType() == "GiftPaper")
    {
      if (_LeftHand != NULL)
	return ;
      _LeftHand = wrap->takeMe();
      if (_LeftHand == NULL)
	return ;
      _LeftHand->isTaken();
    }
  else
    {
      if (_RightHand != NULL)
	return ;
      _RightHand = wrap->takeMe();
      if (_RightHand == NULL)
	return ;
      _RightHand->isTaken();
    }
}

void	ElfOfPePeNoel::openWrap(Wrap *wrap){
  wrap->openMe();
}

void	ElfOfPePeNoel::closeWrap(Wrap *wrap){
  wrap->closeMe();
}

void	ElfOfPePeNoel::putTable(Object *obj){
  _Table->Put(obj);
}

Object*	ElfOfPePeNoel::takeTable(std::string type){
  return(_Table->Take(type));
}

void	ElfOfPePeNoel::lookTable(){

}

Wrap*	ElfOfPePeNoel::takeConvoyer(){
  return(_Convoyer->take());
}

std::string          ElfOfPePeNoel::lookConvoyer(){
  return(_Convoyer->look());
}


void	ElfOfPePeNoel::wrapAGift(){
  while ((_LeftHand = takeTable("Toy")) == NULL)
   _Table->addToy();

  /*if ((_LeftHand = takeTable("Toy")) == NULL)
    {
      std::cerr << "There is no toy to wrap !" << std::endl;
      return ;
      }*/
  std::cout << *_LeftHand;
  in();
  while (lookConvoyer() != "Box")
    {
      _RightHand = takeConvoyer();
      putTable(_RightHand);
      in();
    }
  _RightHand = takeConvoyer();
  std::cout << *_RightHand;
  ((Box *)(_RightHand))->openMe();
  ((Box *)(_RightHand))->wrapMeThat(_LeftHand);
  ((Box *)(_RightHand))->closeMe();

  in();
  while (lookConvoyer() != "GiftPaper")
    {
      _LeftHand = takeConvoyer();
      putTable(_LeftHand);
      in();
    }
  _LeftHand = takeConvoyer();
  ((GiftPaper *)(_LeftHand))->wrapMeThat(((Box *)(_RightHand)));
  _Convoyer->put(((GiftPaper *)(_LeftHand)));
  std::cout << lookConvoyer() << std::endl;
  out();
}

void	ElfOfPePeNoel::in(){
  _Convoyer->in();
  std::cout << "whistles while working" << std::endl;
}

void	ElfOfPePeNoel::out(){
  _Convoyer->out();
}
