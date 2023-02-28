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

SRC			=	src/Components/AComponent.cpp	\
				src/Components/ComponentFactory.cpp \
				src/Components/Pins/APin.cpp	\
				src/Components/Pins/DummyPin.cpp	\
				src/Components/Gates/AndComponent.cpp	\
				src/Components/Gates/NotComponent.cpp	\
				src/Components/Gates/OrComponent.cpp	\
				src/Components/Gates/XorComponent.cpp	\
				src/Components/Static/FalseComponent.cpp	\
				src/Components/Static/TrueComponent.cpp	\
				src/Components/IO/ClockComponent.cpp	\
				src/Components/IO/InputComponent.cpp	\
				src/Components/IO/OutputComponent.cpp	\
				src/Components/Advanced/C4001.cpp   \
				src/Components/Advanced/C4011.cpp   \
				src/Components/Advanced/C4030.cpp   \
				src/Components/Advanced/C4069.cpp   \
				src/Components/Advanced/C4071.cpp   \
				src/Components/Advanced/C4081.cpp   \
				src/Components/Advanced/C4512.cpp   \
				src/Parsing/CommandLine.cpp	\
				src/Parsing/Parser.cpp	\
				src/Utils/Tristate.cpp	\
				src/Components/Circuit.cpp

OBJ			=	$(SRC:%.cpp=%.o) $(MAIN:%.cpp=%.o)

TESTS_SRC	=	$(wildcard tests/*.cpp)

TESTS_OBJ	=	$(TESTS_SRC:%.cpp=%.o)

CXXFLAGS	=	$(INCLUDES) -Wall -Wextra -Wshadow -Wpedantic -Iinclude
CXXFLAGS	+=	-I ./src	\
				-I ./src/Parsing	\
				-I ./src/Utils	\
				-I ./src/Components	\
				-I ./src/Components/Advanced	\
				-I ./src/Components/Gates	\
				-I ./src/Components/IO	\
				-I ./src/Components/Pins	\
				-I ./src/Components/Static

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
