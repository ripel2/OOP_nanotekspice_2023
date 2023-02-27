/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "APin.hpp"
#include "DummyPin.hpp"

std::shared_ptr<nts::DummyPin> dummy_pin = std::make_shared<nts::DummyPin>();

/**
 * @brief Simulates a tick of a component
 * @param tick The tick to simulate
*/
void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

/**
 * @brief Sets a link between a pin of the current component and a pin of another component
 * @param pin The pin of the current component
 * @param other The other component
 * @param otherPin The pin of the other component
*/
void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::shared_ptr<APin> input = std::make_shared<APin>(otherPin, other);

    _pins.insert(std::make_pair(pin, std::move(input)));
}

/**
 * @brief Gets the pin object of the current component given a pin number
 * @param pin The pin number
 * @returns The pin object
*/
std::shared_ptr<nts::IPin> nts::AComponent::getLink(std::size_t pin) const
{
    if (_pins.find(pin) != _pins.end())
        return _pins.at(pin);
    return dummy_pin;
}
