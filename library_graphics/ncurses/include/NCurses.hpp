//
// NCurses.hpp for NCurses in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/ncurses
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:36 2015 Antoine Plaskowski
// Last update Sun Apr  5 02:18:31 2015 Antoine Plaskowski
//

#ifndef		NCURSES_HPP_
# define	NCURSES_HPP_

# include	<curses.h>
# include	"IGraph.hpp"

class		NCurses : public IGraph
{
public:
  NCurses(size_t const x, size_t const y);
  ~NCurses(void);
  bool	display(void);
  bool	update(Map const &map);
  bool	event(Event &event);
public:
  //  WINDOW	*m_screen;
};

#endif		/* !NCURSES_HPP_ */
