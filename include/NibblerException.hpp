//
// NibblerException.hpp for NibblerException in /home/costa_b/rendu/cpp_nibbler/include
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Apr  1 15:38:40 2015 Kevin Costa
// Last update Wed Apr  1 16:02:26 2015 Antoine Plaskowski
//

#ifndef		NIBBLEREXCEPTION_HPP_
# define	NIBBLEREXCEPTION_HPP_

#include	<string>
#include	<exception>

class NibblerException : public std::exception
{
public:
  NibblerException(std::string const &error) throw();
  virtual ~NibblerException(void) throw();
  virtual char const *what(void) const throw();
private:
  std::string	m_error;
};

#endif		/* !NIBBLEREXCEPTION_HPP_ */
