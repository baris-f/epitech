#ifndef ELFOFPEPENOEL_HH
#define ELFOFPEPENOEL_HH

#include "IElf.hh"
#include "ConveyorBeltPePeNoel.hh"
#include "TablePePeNoel.hh"
#include "Toy.hh"

class ElfOfPePeNoel : IElf{
protected:
  TablePePeNoel *_Table;
  ConveyorBeltPePeNoel *_Convoyer;
  Object*	_LeftHand;
  Object*	_RightHand;

public:
  ElfOfPePeNoel();
  ElfOfPePeNoel(ElfOfPePeNoel const &);
  ~ElfOfPePeNoel();
  ElfOfPePeNoel &operator=(ElfOfPePeNoel const &);

  virtual void wrapThat(Wrap *, Object *);
  virtual void takeInWrap(Wrap *);
  virtual void openWrap(Wrap *);
  virtual void closeWrap(Wrap *);
  virtual void putTable(Object *);
  virtual Object*	takeTable(std::string);
  virtual void lookTable();
  virtual Wrap*       takeConvoyer();
  virtual std::string          lookConvoyer();
  virtual void in();
  virtual void out();
  virtual void wrapAGift();
};

#endif
