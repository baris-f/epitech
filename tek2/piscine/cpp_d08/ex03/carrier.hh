//
// carrier.hh for carrer in /home/baris_f/rendu/tek2/cpp_d08/ex03
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 11 21:56:10 2017 baris_f
// Last update Wed Jan 11 23:15:53 2017 baris_f
//

#include "droid.hh"

class	Carrier{
public :
  Carrier(std::string Id = "");
  ~Carrier();
  Droid	*operator<<(Droid*);
  Droid	const *operator>>(Droid* const);
  Droid*	operator[](int const) const;
  Carrier&		operator~();
  bool		operator()(int x, int y);
  size_t		operator<<(size_t &);
private :
  std::string	_Id;
  size_t	_Energy;
  size_t const	_Attack;
  size_t const	_Toughness;
  size_t	_Speed;
  Droid*	_Droids[5];
public :
  size_t	nbDroids() const;
  size_t	getSpeed() const;
  void		setSpeed(size_t);
  size_t	getEnergy() const;
  void		setEnergy(size_t);
  std::string	getId() const;
  void		setId(std::string);
};

std::ostream&   operator<<(std::ostream& os, Carrier const&);
