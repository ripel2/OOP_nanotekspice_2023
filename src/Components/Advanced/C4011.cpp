/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4011
*/

#include "C4011.hpp"

/**
 * @brief Computes the value of the C4011 gate
 * @param pin The pin to compute
 * @returns The value of the pin
 */
nts::Tristate nts::C4011::compute(std::size_t pin)
{
    if (pin == 3)
        return !(getLink(1)->compute() & getLink(2)->compute());
    if (pin == 4)
        return !(getLink(5)->compute() & getLink(6)->compute());
    if (pin == 10)
        return !(getLink(8)->compute() & getLink(9)->compute());
    if (pin == 11)
        return !(getLink(12)->compute() & getLink(13)->compute());
    return nts::UNDEFINED;
}
