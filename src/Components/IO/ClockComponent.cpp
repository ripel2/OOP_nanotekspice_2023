/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

/**
 * @brief Constructor of the clock component
*/
nts::ClockComponent::ClockComponent()
    : InputComponent()
{
}

/**
 * @brief Destructor of the clock component
*/
nts::ClockComponent::~ClockComponent()
{
}

/**
 * @brief Computes the output of the clock component
 * @param pin The pin to compute
 * @returns The current state of the clock component
 * @note This function only computes the state of the first pin, as
 * the clock component only has one pin
*/
nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return InputComponent::compute(pin);
}

/**
 * @brief Simulates a tick of the clock component
 * @param tick The current tick
 * @note This function is used to update the state of the clock
*/
void nts::ClockComponent::simulate(std::size_t tick)
{
    InputComponent::simulate(tick);
    InputComponent::setState(!InputComponent::compute(1));
}
