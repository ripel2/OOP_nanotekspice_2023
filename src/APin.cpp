/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** APin
*/

#include "APin.hpp"
#include "IComponent.hpp"

nts::APin::APin(std::size_t pin, nts::IComponent &component)
    : _state(nts::UNDEFINED), _pin(pin), _component(component)
{

}

std::size_t nts::APin::getPin() const
{
    return _pin;
}

void nts::APin::setPin(std::size_t pin)
{
    _pin = pin;
}

nts::IComponent &nts::APin::getComponent() const
{
    return _component;
}

nts::Tristate nts::APin::getState() const
{
    return _state;
}

void nts::APin::setState(nts::Tristate state)
{
    _state = state;
}

nts::Tristate nts::APin::compute()
{
    nts::Tristate state = _component.compute(_pin);

    return state;
}
