//
// Map.hpp for Map in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 17:15:22 2015 Antoine Plaskowski
// Last update Sun Apr  5 04:38:26 2015 Antoine Plaskowski

#ifndef		MAP_HPP_
# define	MAP_HPP_

# include	<iostream>
# include	<vector>
# include	"stddef.h"

class	Map
{
public:
  enum Object
    {
      NOTHING,
      HEAD,
      BODY,
      TAIL,
      FRUIT
    };
public:
  Map(size_t const x = 42, size_t const y = 42);
  ~Map(void);
  Object	getValue(size_t const x, size_t const y) const;
  void	setValue(size_t const x, size_t const y, Object const value);
  void	reset(void);
  bool	full(void) const;
  size_t	getX(void) const;
  size_t	getY(void) const;
private:
  size_t	m_x;
  size_t	m_y;
  std::vector<Object>	m_map;
};

std::ostream	&operator<<(std::ostream &os, Map const &map);

#endif		/* !MAP_HPP_ */
