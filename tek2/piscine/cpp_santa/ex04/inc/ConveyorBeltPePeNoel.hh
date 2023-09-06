#ifndef conveyorbelt_hh
#define conveyorbelt_hh

#include <iostream>

#include "Object.hh"
#include "IConveyorBelt.hh"
#include "Box.hh"
#include "GiftPaper.hh"

class ConveyorBeltPePeNoel : public IConveyorBelt {
public:
  ConveyorBeltPePeNoel();
  virtual ~ConveyorBeltPePeNoel();

  virtual void in();
  virtual void put(Wrap*);
  virtual void out();
  virtual std::string look();

  Wrap *take();

private:
  Wrap* _object;
  bool _lastIsBox;

};

#endif
