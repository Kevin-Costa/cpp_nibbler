//
// start_lib.cpp for start_lib in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/sfml
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Wed Apr  1 18:20:38 2015 Antoine Plaskowski
// Last update Wed Apr  1 19:46:28 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<iostream>
#include	<string.h>
#include	"start_lib.hpp"

const char	lib_interp[] __attribute__((section(".interp"))) = "/lib/ld-linux-x86-64.so.2";

void		start_lib(void)
{
  std::ios_base::Init	init;
  std::cout << "coucou" << std::endl;
  _exit(0);
}
