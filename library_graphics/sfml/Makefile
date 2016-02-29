##
## Makefile for lib_nibbler_sfml in /home/plasko_a/projet/epitech/PSU_2014_lib_nibbler_sfml
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 02:10:40 2015 Antoine Plaskowski
## Last update Sun Apr  5 02:28:11 2015 Antoine Plaskowski
##

NAME		=	lib_nibbler_sfml.so

CXX		?=	g++

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	-l sfml-graphics -l sfml-window

INCLUDE		=	-I include -I ../../include

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
LDFLAGS		+=	-shared -Wl,-e,start_lib -Wl,-soname,$(NAME)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

SRC		=

include			source.mk

DPD		=	$(SRC:.cpp=.dpd)

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(DPD)

fclean		:	clean
			$(RM) -f $(NAME)

re		:	fclean all

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.cpp .dpd.cpp

include			$(DPD)
