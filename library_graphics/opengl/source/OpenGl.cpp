//
// OpenGl.cpp for OpenGl in /home/plasko_a/projet/cplusplus/cpp_nibbler/library_graphics/openGl
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 08:13:18 2015 Antoine Plaskowski
// Last update Sun Apr  5 23:01:12 2015 Kevin Costa
//

#include	<SFML/Window.hpp>
#include	"OpenGl.hpp"
#include	"NibblerException.hpp"

OpenGl::OpenGl(size_t const x, size_t const y) :
  _vm(x * 25, y * 25)
{
  if (x * 25 > 1920 || y * 25 > 1080)
    throw (NibblerException("Can't open a window"));
  _nib.Create(_vm, "Nibbler OpenGl");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, x * 25, y * 25, 0);
}

OpenGl::~OpenGl(void)
{
  _nib.Close();
}

bool	OpenGl::display(void)
{
  _nib.Display();
  return (true);
}

bool	OpenGl::event(Event &event)
{
  sf::Event	sf_event;

  while (_nib.GetEvent(sf_event) == true)
    {
      if (sf_event.Type == sf::Event::Closed)
	event.setType(Event::QUIT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Escape))
	event.setType(Event::QUIT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Right))
	event.setType(Event::RIGHT);
      else if ((sf_event.Type == sf::Event::KeyPressed) && (sf_event.Key.Code == sf::Key::Left))
	event.setType(Event::LEFT);
      else
	continue;
      return (true);
    }
  return (false);
}

bool	OpenGl::update(Map const &map)
{
  glClear(GL_COLOR_BUFFER_BIT);
  for (size_t i = 0; i < map.getX(); i++)
    for (size_t j = 0; j < map.getY(); j++)
      {
	switch (map.getValue(i, j))
	  {
	  case Map::NOTHING:
	    break;
	  case Map::HEAD:
	    glBegin(GL_POLYGON);
	    glColor3ub(255, 0, 0);
	    glVertex2d(i * 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25 + 25);
	    glVertex2d(i * 25, j * 25 + 25);
	    glEnd();
	    break;
	  case Map::BODY:
	    glBegin(GL_POLYGON);
	    glColor3ub(0, 255, 0);
	    glVertex2d(i * 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25 + 25);
	    glVertex2d(i * 25, j * 25 + 25);
	    glEnd();
	    break;
	  case Map::TAIL:
	    glBegin(GL_POLYGON);
	    glColor3ub(255, 255, 0);
	    glVertex2d(i * 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25 + 25);
	    glVertex2d(i * 25, j * 25 + 25);
	    glEnd();
	    break;
	  case Map::FRUIT:
	    glBegin(GL_POLYGON);
	    glColor3ub(255, 255, 255);
	    glVertex2d(i * 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25);
	    glVertex2d(i * 25 + 25, j * 25 + 25);
	    glVertex2d(i * 25, j * 25 + 25);
	    glEnd();
	    break;
	  }
      }
  return true;
}

IGraph *init_graph(size_t const x, size_t const y)
{
  return (new OpenGl(x, y));
}
