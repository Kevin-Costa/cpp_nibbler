//
// main.cpp for main in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Mar 12 06:21:05 2015 Antoine Plaskowski
// Last update Sun Apr  5 21:10:33 2015 Antoine Plaskowski
//

#include	<iostream>
#include	<sstream>
#include	<exception>
#include	"Snake.hpp"

int		main(int argc, char **argv)
{
  if (argc != 4)
    {
      std::cout << "Usage : <weidth> <high> <lib>" << std::endl;
      return (1);
    }
  std::stringstream	ss;
  size_t	width;
  size_t	height;

  ss << argv[1];
  ss >> width;
  ss.clear();
  ss << argv[2];
  ss >> height;
  size_t	res = 0;
  try
    {
      Snake	snake(argv[3], width, height);
      
      res = snake.play();
    }
  catch (std::exception const &e)
    {
      std::cerr << e.what() << std::endl;
    }
  std::cout << "You grew up of " << res << std::endl;
  return (0);
}
