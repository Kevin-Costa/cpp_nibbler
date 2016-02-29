//
// SnakeException.cpp for SnakeException in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Apr  1 15:49:45 2015 Kevin Costa
// Last update Sat Apr  4 19:58:27 2015 Antoine Plaskowski
//

#include <string>
#include "SnakeException.hpp"

SnakeException::SnakeException(std::string const &str) throw() :
  NibblerException(str)
{
}

SnakeException::~SnakeException(void) throw()
{
}
