#include "GameObject.hpp"

GameObject::GameObject(std::string n, std::string f, float x, float y) : _name(n)
{
  _texture = new sf::Texture;
  if (! _texture->loadFromFile("./res/" + f))
    std::cerr << "Erreur chargement texure"<< std::endl;
  _sprite = new sf::Sprite(*_texture);
  _sprite->setPosition(x, y);
}

const	std::string&	GameObject::getName() const
{
  return (_name);
}

void	GameObject::draw(sf::RenderWindow* window) const
{
  window->draw(*_sprite);
}

void	GameObject::move(float x, float y)
{
  _sprite->move(x, y);
}
