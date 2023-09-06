#ifndef BUILDING_HPP_
# define BUILDING_HPP_

#include "Entity.hpp"
#include "IListener.hpp"

class Building : public Entity, public IListener {
public:
  Building(sf::Texture*, const std::string);
  ~Building(){};
};

#endif /* !BUILDING_HPP_ */
