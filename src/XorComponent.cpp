/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    nts::Tristate nts2 = getLink(2)->compute();
    return nts1 ^ nts2;
}
