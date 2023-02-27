/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** APin
*/

#include "APin.hpp"
#include "IComponent.hpp"

/**
 * @brief Constructor for the APin object
 * @param pin The pin number of the pin
 * @param component The component the pin is linked to
*/
nts::APin::APin(std::size_t pin, nts::IComponent &component)
    : _pin(pin), _component(component), _state(nts::UNDEFINED)
{

}

/**
 * @brief Gets the current pin number of the pin object
 * @returns The pin number of the pin
*/
std::size_t nts::APin::getPin() const
{
    return _pin;
}

/**
 * @brief Sets the pin number of the pin object
 * @param pin The pin number to set
*/
void nts::APin::setPin(std::size_t pin)
{
    _pin = pin;
}

/**
 * @brief Gets the component the pin is linked to
 * @returns The component the pin is linked to
*/
nts::IComponent &nts::APin::getComponent() const
{
    return _component;
}

/**
 * @brief Gets the state of the pin
 * @returns The state of the pin
*/
nts::Tristate nts::APin::getState() const
{
    return _state;
}

/**
 * @brief Sets the state of the pin
 * @param state The state to set the pin to
*/
void nts::APin::setState(nts::Tristate state)
{
    _state = state;
}

/**
 * @brief Computes the state of the pin
 * @returns The state of the pin
*/
nts::Tristate nts::APin::compute()
{
    nts::Tristate state = _component.compute(_pin);

    return state;
}
