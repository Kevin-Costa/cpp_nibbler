//
// Event.cpp for Event in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Apr  5 00:41:03 2015 Antoine Plaskowski
// Last update Sun Apr  5 00:43:30 2015 Antoine Plaskowski
//

#include	"Event.hpp"

Event::Event(void) :
  m_type(NONE)
{
}

void		Event::setType(Type type)
{
  m_type = type;
}

Event::Type	Event::getType(void) const
{
  return (m_type);
}
