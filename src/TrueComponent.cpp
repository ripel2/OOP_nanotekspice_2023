/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return nts::TRUE;
}
