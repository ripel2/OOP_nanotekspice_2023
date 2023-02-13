##
## EPITECH PROJECT, 2023
## OOP_nanotekspice_2023
## File description:
## Makefile
##

GCC			=	g++
RM			=	-rm

NAME		=	nanotekspice

MAIN		=	src/Main.cpp

SRC			=	src/AComponent.cpp	\
				src/APin.cpp	\
				src/AndComponent.cpp	\
				src/OrComponent.cpp	\
				src/XorComponent.cpp	\
				src/NotComponent.cpp	\
				src/FalseComponent.cpp	\
				src/TrueComponent.cpp	\
				src/Tristate.cpp	\
				src/Circuit.cpp	\
				src/ReadStandardInput.cpp	\

OBJ			=	$(SRC:%.cpp=%.o) $(MAIN:%.cpp=%.o)

TESTS_SRC	=	$(wildcard tests/*.cpp)

TESTS_OBJ	=	$(TESTS_SRC:%.cpp=%.o)

CXXFLAGS	=	-Wall -Wextra -Wshadow -Wpedantic -Iinclude

TESTS_FLAGS	=	-lcriterion
COVERAGE	=	--coverage -fprofile-arcs -ftest-coverage

all:		$(NAME)

$(NAME):	$(OBJ)
	$(GCC) -o $(NAME) $(OBJ) -g3

clean:
	find . -name "*~" -delete -or -name "#*#" -delete
	find . -name "*.o" -delete
	find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:		clean
	$(RM) -f $(NAME)

re:		fclean $(NAME)

tests_run:	LDFLAGS += $(TESTS_FLAGS)
tests_run:	CFLAGS += $(COVERAGE)
tests_run:	clean
	@$(GCC) -o unit_tests $(TESTS_SRC) $(SRC) $(CXXFLAGS) $(LDFLAGS) -I./
	./unit_tests --always-succeed
	$(RM) unit_tests

coverage:	tests_run
	gcovr . --exclude tests/
	gcovr .	-b --exclude tests/
	$(MAKE) clean

debug:		CFLAGS += -g
debug:		re

.PHONY:	all clean fclean re
