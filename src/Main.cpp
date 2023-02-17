/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023
** File description:
** Main
*/

#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    nts::Circuit circuit;
    nts::Parser parser = nts::Parser(circuit, av[1]);
    try {
        parser.parseCircuit();
    } catch (nts::Parser::ParserException &e) {
        std::cerr << av[0] << ": " << e.what() << std::endl;
        return (84);
    }
    return (0);
}
