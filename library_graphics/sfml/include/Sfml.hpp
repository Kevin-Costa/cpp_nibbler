//
// Sfml.hpp for Sfml in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/sfml
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:36 2015 Antoine Plaskowski
// Last update Sun Apr  5 04:34:38 2015 Kevin Costa
//

#ifndef		SFML_HPP_
# define	SFML_HPP_

# include	"IGraph.hpp"
# include        <SFML/Graphics.hpp>

class		Sfml : public IGraph
{
public:
  Sfml(size_t const x, size_t const y);
  ~Sfml();
  bool	display(void);
  bool	event(Event &event);
  bool	update(Map const &map);
private:
  sf::VideoMode		_vm;
  sf::RenderWindow	_nib;
};

#endif		/* !SFML_HPP_ */
