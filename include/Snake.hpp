//
// Snake.hpp for Snake in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 03:50:46 2015 Antoine Plaskowski
// Last update Sun Apr  5 06:04:45 2015 Antoine Plaskowski
//

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

# include	<list>
# include	<stddef.h>
# include	<sys/time.h>
# include	<string>
# include	"Dll.hpp"
# include	"IGraph.hpp"
# include	"Map.hpp"

class	Snake
{
public:
  enum	Sens
    {
      SUD,
      WEST,
      NORD,
      EAST
    };
private:
  struct	Body
  {
    size_t	x;
    size_t	y;
    Map::Object	part;
  };
public:
  Snake(std::string const &path_lib, size_t const x = 42, size_t const y = 42, size_t const snake = 4);
  ~Snake(void);
  size_t	play(void);
private:
  bool	fruit(void);
  void	put(void);
  Sens	sens(Event::Type type) const;
  bool	move(void);
  bool	colision(size_t const x, size_t const y) const;
private:
  Dll const	m_dll;
  fct_init_graph const	m_ptr_init_graph;
  IGraph	*m_graph;
  Map	m_map;
  std::list<Body>	m_body;
  Sens	m_sens;
  size_t	m_xhead;
  size_t	m_yhead;
  size_t	m_xfruit;
  size_t	m_yfruit;
};

#endif		/* !SNAKE_HPP_ */
