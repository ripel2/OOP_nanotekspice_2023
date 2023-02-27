/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
    : InputComponent()
{
}

nts::ClockComponent::~ClockComponent()
{
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return InputComponent::compute(pin);
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    InputComponent::simulate(tick);
    InputComponent::setState(!InputComponent::compute(1));
}
