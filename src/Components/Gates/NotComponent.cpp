/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

#include "APin.hpp"

/**
 * @brief Computes the value of the Not gate
 * @param pin The pin to compute
 * @returns The value of the pin
 * @note The pin must be 2, as the NotComponent only has 2 pins and
 * the second pin is the output
*/
nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != 2)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    return !nts1;
}
