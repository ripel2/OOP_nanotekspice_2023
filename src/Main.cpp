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
    parser.parseCircuit();
    return (0);
}
