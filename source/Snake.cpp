//
// Snake.cpp for Snake in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Mar 31 06:59:19 2015 Antoine Plaskowski
// Last update Sun Apr  5 22:13:04 2015 Antoine Plaskowski
//

#include	<stddef.h>
#include	<stdlib.h>
#include	<time.h>
#include	<string.h>
#include	<errno.h>
#include	"Snake.hpp"
#include	"SnakeException.hpp"

Snake::Snake(std::string const &path_lib, size_t const x, size_t const y, size_t const snake) :
  m_dll(path_lib),
  m_ptr_init_graph(m_dll.getSymbole<fct_init_graph>("init_graph")),
  m_graph((*m_ptr_init_graph)(x, y)),
  m_map(x, y),
  m_body(),
  m_sens(WEST),
  m_xhead(x / 2),
  m_yhead(y / 2),
  m_xfruit(m_xhead),
  m_yfruit(m_yhead)
{
  srand(time(NULL));

  Body	body;

  body.x = m_xhead;
  body.y = m_yhead;
  for (size_t i = 3; i < snake; i++)
    {
      body.part = Map::BODY;
      m_body.push_front(body);
    }
  body.part = Map::TAIL;
  m_body.push_front(body);
}

bool	Snake::fruit(void)
{
  if (m_map.full() == true)
    return (true);

  size_t	i;
  size_t	j;
  do
    {
      i = rand() % m_map.getX();
      j = rand() % m_map.getY();
    }
  while (m_map.getValue(i, j) != Map::NOTHING);
  m_xfruit = i;
  m_yfruit = j;
  return (false);
}

void	Snake::put(void)
{
  m_map.reset();
  for (std::list<Body>::iterator it = m_body.begin(); it != m_body.end(); it++)
    m_map.setValue(it->x, it->y, it->part);
  m_map.setValue(m_xhead, m_yhead, Map::HEAD);
}

bool	Snake::move(void)
{
  std::list<Body>::iterator it = m_body.begin();
  std::list<Body>::iterator prev = it++;

  while (it != m_body.end())
    {
      prev->x = it->x;
      prev->y = it->y;
      prev = it++;
    }
  prev->x = m_xhead;
  prev->y = m_yhead;
  switch (m_sens)
    {
    case EAST:
      m_xhead++;
      if (m_xhead == m_map.getX())
	return (true);
      break;
    case WEST:
      if (m_xhead == 0)
	return (true);
      m_xhead--;
      break;
    case SUD:
      m_yhead++;
      if (m_yhead == m_map.getY())
	return (true);
      break;
    case NORD:
      if (m_yhead == 0)
	return (true);
      m_yhead--;
      break;
    }
  return (colision(m_xhead, m_yhead));
}

bool	Snake::colision(size_t const x, size_t const y) const
{
  for (std::list<Body>::const_iterator it = m_body.begin(); it != m_body.end(); it++)
    if (it->x == x && it->y == y)
      return (true);
  return (false);
}

size_t	Snake::play(void)
{
  struct timespec	wait = {0, 999999999};
  Event	event;

  do
    {
      put();
      if (m_xfruit == m_xhead && m_yfruit == m_yhead)
	{
	  Body	&front = m_body.front();
	  m_body.push_front(front);
	  front.part = Map::BODY;
	  if (fruit() == true)
	    return (m_body.size());
	  wait.tv_nsec -= wait.tv_nsec / 10;
	  put();
	}
      m_map.setValue(m_xfruit, m_yfruit, Map::FRUIT);
      m_graph->update(m_map);
      m_graph->display();
      nanosleep(&wait, NULL);
      if (m_graph->event(event) == true)
      	{
      	  if (event.getType() == Event::QUIT)
      	    break;
      	  m_sens = sens(event.getType());
      	}
    }
  while (move() == false);
  return (m_body.size());
}

Snake::Sens	Snake::sens(Event::Type const type) const
{
  switch (type)
    {
    case Event::LEFT:
      switch (m_sens)
	{
	case SUD:
	  return (EAST);
	case EAST:
	  return (NORD);
	case NORD:
	  return (WEST);
	case WEST:
	  return (SUD);
	}
    case Event::RIGHT:
      switch (m_sens)
	{
	case SUD:
	  return (WEST);
	case WEST:
	  return (NORD);
	case NORD:
	  return (EAST);
	case EAST:
	  return (SUD);
	}
    default:
      return (m_sens);
    }
}

Snake::~Snake(void)
{
  delete m_graph;
}
