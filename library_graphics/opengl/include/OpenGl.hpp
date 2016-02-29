//
// OpenGl.hpp for OpenGl in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/openGl
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:36 2015 Antoine Plaskowski
// Last update Sun Apr  5 20:04:00 2015 Kevin Costa
//

#ifndef		OPENGL_HPP_
# define	OPENGL_HPP_

# include	"IGraph.hpp"
# include	<SFML/Window.hpp>

class		OpenGl : public IGraph
{
public:
  OpenGl(size_t const x, size_t const y);
  ~OpenGl();
  bool	display(void);
  bool	event(Event &event);
  bool	update(Map const &map);
private:
  sf::VideoMode		_vm;
  sf::Window		_nib;
};

#endif		/* !OPENGL_HPP_ */
