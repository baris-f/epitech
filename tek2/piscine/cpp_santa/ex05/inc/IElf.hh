#ifndef IELF_HH
#define IELF_HH

#include "Object.hh"
#include "Wrap.hh"

class IElf {
public:
  virtual ~IElf(){};
  virtual void		wrapThat(Wrap *, Object *) = 0;
  virtual void		openWrap(Wrap *) = 0;
  virtual void		closeWrap(Wrap *) = 0;
  virtual void		putTable(Object *) = 0;
  virtual Object*	takeTable(std::string) = 0;
  virtual void		lookTable() = 0;
  virtual Wrap*		takeConvoyer() = 0;
  virtual std::string	lookConvoyer() = 0;
  virtual void in() = 0;
  virtual void out() = 0;
  virtual void wrapAGift() = 0;
};

#endif /* IELF_HH */
