/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OrComponent
*/

#include "OrComponent.hpp"

/**
 * @brief Computes the value of the Or gate
 * @param pin The pin to compute
 * @returns The value of the pin
 * @note The pin must be 3, as the OrComponent only has 3 pins and
 * the third pin is the output
*/
nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    nts::Tristate nts2 = getLink(2)->compute();
    return nts1 | nts2;
}
