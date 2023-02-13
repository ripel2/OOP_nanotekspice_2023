/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023
** File description:
** Main
*/

#include "Circuit.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    nts::Circuit circuit;
    nts::ParseCircuit(circuit, av[1]);
    return (0);
}
