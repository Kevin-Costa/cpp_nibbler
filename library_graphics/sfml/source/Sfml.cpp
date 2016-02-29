//
// Sfml.cpp for Sfml in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/sfml
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:18 2015 Antoine Plaskowski
// Last update Thu Apr  9 12:14:58 2015 Kevin Costa
//

#include	<SFML/Graphics.hpp>
#include	"Sfml.hpp"
#include	"NibblerException.hpp"

Sfml::Sfml(size_t const x, size_t const y) :
  _vm(x * 25, y * 25)
{
  // if (x * 25 > 1920 || y * 25 > 1080)
  //   throw (NibblerException("Can't open a window"));
  _nib.Create(_vm, "Nibbler SFML");
}

Sfml::~Sfml(void)
{
  _nib.Close();
}

bool	Sfml::display(void)
{
  _nib.Display();
 return (true);
}

bool	Sfml::event(Event &event)
{
  sf::Event	sf_event;

  while (_nib.GetEvent(sf_event) == true)
    {
      if (sf_event.Type == sf::Event::Closed)
	event.setType(Event::QUIT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Escape))
	event.setType(Event::QUIT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Right))
	event.setType(Event::RIGHT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Left))
	event.setType(Event::LEFT);
      else
	continue;
      return (true);
    }
  return (false);
}
bool Sfml::update(Map const &map)
{
  sf::Shape block;

  _nib.Clear();
  for (size_t i = 0; i < map.getX(); i++)
    for (size_t j = 0; j < map.getY(); j++)
      {
	switch (map.getValue(i, j))
	{
	case Map::NOTHING:
	  block = sf::Shape::Rectangle(i * 25, j * 25, i * 25 + 25, j * 25 + 25, sf::Color::Black);
	  break;
	case Map::HEAD:
	  block = sf::Shape::Rectangle(i * 25, j * 25, i * 25 + 25, j * 25 + 25, sf::Color::Red);
	  break;
	case Map::BODY:
	  block = sf::Shape::Rectangle(i * 25, j * 25, i * 25 + 25, j * 25 + 25, sf::Color::Green);
	  break;
	case Map::TAIL:
	  block = sf::Shape::Rectangle(i * 25 , j * 25 , i * 25 + 25, j * 25 + 25, sf::Color::Yellow);
	  break;
	case Map::FRUIT:
	  block = sf::Shape::Rectangle(i * 25, j * 25, i * 25 + 25, j * 25 + 25, sf::Color::White);
	  break;
	}
      _nib.Draw(block);
      }
  return (true);
}

IGraph  *init_graph(size_t const x, size_t const y)
{
  return (new Sfml(x, y));
}
