//
// Exception.cpp for Exception.cpp in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Tue Mar 31 15:23:37 2015 Kevin Costa
// Last update Wed Apr  1 15:59:15 2015 Antoine Plaskowski
//

#include	<string>
#include	"NibblerException.hpp"

NibblerException::NibblerException(std::string const &error) throw() :
  m_error(error)
{
}

NibblerException::~NibblerException(void) throw()
{
}

char const	*NibblerException::what(void) const throw()
{
  return (m_error.c_str());
}
