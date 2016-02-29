//
// Map.cpp for Map in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Mar 30 17:39:54 2015 Kevin Costa
// Last update Sun Apr  5 22:09:19 2015 Antoine Plaskowski
//

#include	<stdint.h>
#include	<sstream>
#include	"Map.hpp"
#include	"MapException.hpp"

Map::Map(size_t const x, size_t const y) :
  m_x(x),
  m_y(y),
  m_map(m_x * m_y, NOTHING)
{
}

Map::~Map(void)
{
}

Map::Object	Map::getValue(size_t const x, size_t const y) const
{
  size_t const	i = m_x * y + x;

  if (i >= m_map.size())
    {
      std::stringstream ss;

      ss << "getValue : Invalid range " << x << " " << y;
      throw (MapException(ss.str()));
    }
  return (m_map[i]);
}

void	Map::setValue(size_t const x, size_t const y, Object const value)
{
  size_t const	i = m_x * y + x;

  if (i >= m_map.size())
    {
      std::stringstream ss;

      ss << "setValue : Invalid range " << x << " " << y;
      throw (MapException(ss.str()));
    }
  m_map[i] = value;
}

void	Map::reset(void)
{
  for (size_t i = 0; i < getX(); i++)
    for (size_t j = 0; j < getY(); j++)
      setValue(i, j, NOTHING);
}

bool	Map::full(void) const
{
  for (size_t i = 0; i < getX(); i++)
    for (size_t j = 0; j < getY(); j++)
      if (getValue(i, j) == NOTHING)
	return (false);
  return (true);
}

size_t	Map::getX(void) const
{
  return (m_x);
}

size_t	Map::getY(void) const
{
  return (m_y);
}

std::ostream	&operator<<(std::ostream &os, Map const &map)
{
  for (size_t x = 0; x < map.getX(); x++)
    {
      for (size_t y = 0; y < map.getY(); y++)
	os << map.getValue(x, y);
      os << std::endl;
    }
  return (os);
}
