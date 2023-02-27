/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent()
{
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return getLink(1)->compute();
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
}
