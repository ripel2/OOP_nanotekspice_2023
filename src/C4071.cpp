/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4071
*/

#include "C4071.hpp"

nts::Tristate nts::C4071::compute(std::size_t pin)
{
    if (pin == 3)
        return getLink(1)->compute() | getLink(2)->compute();
    if (pin == 4)
        return getLink(5)->compute() | getLink(6)->compute();
    if (pin == 10)
        return getLink(8)->compute() | getLink(9)->compute();
    if (pin == 11)
        return getLink(12)->compute() | getLink(13)->compute();
    return nts::UNDEFINED;
}
