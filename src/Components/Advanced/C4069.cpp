/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4069
*/

#include "C4069.hpp"

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    if (pin == 2)
        return !getLink(1)->compute();
    if (pin == 4)
        return !getLink(3)->compute();
    if (pin == 6)
        return !getLink(5)->compute();
    if (pin == 8)
        return !getLink(9)->compute();
    if (pin == 10)
        return !getLink(11)->compute();
    if (pin == 12)
        return !getLink(13)->compute();
    return nts::UNDEFINED;
}

