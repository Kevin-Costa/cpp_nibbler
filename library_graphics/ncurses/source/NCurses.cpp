//
// NCurses.cpp for NCurses in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/ncurses
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:18 2015 Antoine Plaskowski
// Last update Sun Apr  5 22:35:06 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"NCurses.hpp"
#include	"Snake.hpp"

NCurses::NCurses(size_t const, size_t const)
{
  initscr();
  if (raw() == ERR)
    std::cerr << "raw mode fail" << std::endl;
  keypad(stdscr, TRUE);
  noecho();
  timeout(0);
}

NCurses::~NCurses(void)
{
  endwin();
}

bool	NCurses::display(void)
{
  refresh();
  return (true);
}

bool	NCurses::update(Map const &map)
{
  erase();
  for (size_t i = 0; i < map.getX(); i++)
    for (size_t j = 0; j < map.getY(); j++)
      switch (map.getValue(i, j))
  	{
  	case Map::NOTHING:
	  mvprintw(j, i, "_");
  	  break;
  	case Map::HEAD:
  	  mvprintw(j, i, "H");
  	  break;
  	case Map::BODY:
  	  mvprintw(j, i, "S");
  	  break;
  	case Map::TAIL:
  	  mvprintw(j, i, "T");
  	  break;
  	case Map::FRUIT:
  	  mvprintw(j, i, "F");
  	  break;
  	}
  return (true);
}

bool	NCurses::event(Event &event)
{
  int	c;

  while ((c = getch()) != ERR)
    {
      switch (c)
	{
	case KEY_LEFT:
	  event.setType(Event::LEFT);
	  return (true);
	case KEY_RIGHT:
	  event.setType(Event::RIGHT);
	  return (true);
	case 'q':
	  event.setType(Event::QUIT);
	  return (true);
	}
    }
  return (false);
}

IGraph	*init_graph(size_t const x, size_t const y)
{
  return (new NCurses(x, y));
}
