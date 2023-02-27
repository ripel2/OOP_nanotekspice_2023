/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent()
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return _state;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_needsUpdate) {
        _state = _incState;
        _needsUpdate = false;
    }
}

void nts::InputComponent::setState(nts::Tristate state)
{
    _incState = state;
    _needsUpdate = true;
}

void nts::InputComponent::dump() const
{
    std::cout << "Input(s):" << std::endl;
    std::cout << '\t' << "input: " << _state << std::endl;
}
