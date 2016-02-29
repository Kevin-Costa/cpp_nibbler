//
// SnakeException.hpp for SnakeException in /home/plasko_a/projet/cplusplus/cpp_nibbler/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Apr  1 15:58:11 2015 Antoine Plaskowski
// Last update Sat Apr  4 19:58:52 2015 Antoine Plaskowski
//

#ifndef		SNAKEEXCEPTION_HPP_
# define	SNAKEEXCEPTION_HPP_

# include	"NibblerException.hpp"

class SnakeException : public NibblerException
{
public:
  SnakeException(std::string const &str) throw();
  virtual ~SnakeException(void) throw();
};

#endif		/* !SNAKEEXCEPTION_HPP_ */
