//
// Event.hpp for Event in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 21:30:40 2015 Antoine Plaskowski
// Last update Sun Apr  5 00:42:54 2015 Antoine Plaskowski
//

#ifndef		EVENT_HPP_
# define	EVENT_HPP_

class		Event
{
public:
  enum	Type
    {
      NONE,
      LEFT,
      RIGHT,
      QUIT
    };
public:
  Event(void);
  Type	getType(void) const;
  void	setType(Type type);
private:
  Type	m_type;
};

#endif		/* !EVENT_HPP_ */
