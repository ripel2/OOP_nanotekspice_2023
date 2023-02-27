/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

/**
 * @brief Constructor of the input component
*/
nts::InputComponent::InputComponent()
{
}

/**
 * @brief Computes the current state of the input component
 * @param pin The pin to compute
 * @returns The current state of the input component
 * @note This function only computes the state of the first pin, as
 * the input component only has one pin
*/
nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return _state;
}

/**
 * @brief Simulates a tick of the input component
 * @param tick The current tick
 * @note This function is used to update the state of the input
*/
void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_needsUpdate) {
        _state = _incState;
        _needsUpdate = false;
    }
}

/**
 * @brief Sets the state of the input component
 * @param state The state to set the input component to
*/
void nts::InputComponent::setState(nts::Tristate state)
{
    _incState = state;
    _needsUpdate = true;
}

/**
 * @brief Dumps the state of the input component
*/
void nts::InputComponent::dump() const
{
    std::cout << "Input(s):" << std::endl;
    std::cout << '\t' << "input: " << _state << std::endl;
}
