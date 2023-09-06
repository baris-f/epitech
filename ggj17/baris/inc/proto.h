#ifndef PROTO_H_
# define PROTO_H_

#include "Unit.hpp"

float   dist(sf::Vector2f pos1, sf::Vector2f pos2);
void    drawShoot(Entity * me, Entity * target);
void    drawShoot(Entity * me, Entity * target);
Entity* findTarget(Entity * me);
void playSound(std::string, bool);



#endif /* !PROTO_H_ */
