/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return nts::FALSE;
}
