/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

/**
 * @brief Constructor of the output component
*/
nts::OutputComponent::OutputComponent()
{
}

/**
 * @brief Destructor of the output component
*/
nts::OutputComponent::~OutputComponent()
{
}

/**
 * @brief Computes the output of the output component
*/
nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return getLink(1)->compute();
}

/**
 * @brief Simulates a tick of the output component
 * @param tick The current tick
 * @note This function does nothing and is implemented only to
 * satisfy the IComponent interface
 */
void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
}
