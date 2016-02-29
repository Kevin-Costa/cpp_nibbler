//
// Mapexception.cpp for Mapexeption in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Apr  1 15:49:45 2015 Kevin Costa
// Last update Wed Apr  1 17:19:43 2015 Antoine Plaskowski
//

#include <string>
#include "MapException.hpp"

MapException::MapException(std::string const &str) throw() :
  NibblerException(str)
{
}

MapException::~MapException(void) throw()
{
}
