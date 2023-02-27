/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** AndComponent
*/

#include "AndComponent.hpp"
#include "Tristate.hpp"
#include "IPin.hpp"

/**
 * @brief Computes the value of the And gate
 * @param pin The pin to compute
 * @returns The value of the pin
 * @note The pin must be 3, as the AndComponent only has 3 pins and
 * the third pin is the output
*/
nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    nts::Tristate nts2 = getLink(2)->compute();
    return nts1 & nts2;
}
