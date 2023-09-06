#ifndef DROID_HH_
# define DROID_HH_

#include <iostream>
#include "droidmemory.hh"

class	Droid{
 public :
  Droid(std::string serial);
  Droid(Droid const &);
  Droid& operator=(Droid const &);
  bool	 operator==(Droid const &) const;
  bool	 operator!=(Droid const &) const;
  size_t	operator<<(size_t &);
  bool	operator()(std::string const *, size_t const);
  ~Droid();
 private :
  std::string	_Id;
  size_t	_Energy;
  size_t const	_Attack;
  size_t const	_Toughness;
  std::string	*_Status;
  DroidMemory	*_BattleData;
 public :
  std::string	getId() const;
  void		setId(std::string Id);
  size_t     	getEnergy() const;
  void		setEnergy(size_t Energy);
  size_t     	getAttack() const;
  size_t     	getToughness() const;
  std::string*	getStatus() const;
  void		setStatus(std::string* Status);
  void		setStatus(std::string Status);
  DroidMemory*	getBattleData() const;
  void		setBattleData(DroidMemory*);
};

std::ostream&	 operator<<(std::ostream&, Droid const&);
#endif /* !DROID_HH_ */
