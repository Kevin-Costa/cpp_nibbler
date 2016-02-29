//
// IGraph.hpp for IGraph in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 16:54:13 2015 Antoine Plaskowski
// Last update Sun Apr  5 02:17:58 2015 Antoine Plaskowski
//

#ifndef		IGRAPH_HPP_
# define	IGRAPH_HPP_

# include	<stddef.h>
# include	"Map.hpp"
# include	"Event.hpp"

class		IGraph
{
public:
  virtual	~IGraph(void);
  virtual bool	display(void) = 0;
  virtual bool	update(Map const &map) = 0;
  virtual bool	event(Event &event) = 0;
};

extern "C"
{
  IGraph	*init_graph(size_t const x, size_t const y);
  typedef	IGraph *(*fct_init_graph)(size_t const x, size_t const y);
}

#endif		/* !IGRAPH_HPP_ */
