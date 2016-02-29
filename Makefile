##
## Makefile for lib_nibbler_nibbler in /home/plasko_a/projet/epitech/PSU_2014_lib_nibbler_nibbler
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 02:10:40 2015 Antoine Plaskowski
## Last update Sun Apr  5 03:26:39 2015 Antoine Plaskowski
##

NAME		=	nibbler

CXX		?=	g++

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	-l dl

INCLUDE		=	-I include

CXXFLAGS	=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic
CXXFLAGS	+=	-fPIC
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang)
CXXFLAGS	+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)
LDFLAGS		+=	-Wl,--export-dynamic

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

SRC		=

include			source.mk

DPD		=	$(SRC:.cpp=.dpd)

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)
			$(MAKE) $(@) -C library_graphics/ncurses
			$(MAKE) $(@) -C library_graphics/sfml
			$(MAKE) $(@) -C library_graphics/opengl

$(NAME)		:	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(DPD)
			$(MAKE) $(@) -C library_graphics/ncurses
			$(MAKE) $(@) -C library_graphics/sfml
			$(MAKE) $(@) -C library_graphics/opengl

fclean		:	clean
			$(RM) -f $(NAME)
			$(MAKE) $(@) -C library_graphics/ncurses
			$(MAKE) $(@) -C library_graphics/sfml
			$(MAKE) $(@) -C library_graphics/opengl

re		:	fclean all
			$(MAKE) $(@) -C library_graphics/ncurses
			$(MAKE) $(@) -C library_graphics/sfml
			$(MAKE) $(@) -C library_graphics/opengl

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.cpp .dpd.cpp

include			$(DPD)
