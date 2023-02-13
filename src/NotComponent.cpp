/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

#include "APin.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != 2)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    return !nts1;
}
