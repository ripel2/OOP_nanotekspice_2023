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

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::shared_ptr<APin> input = std::make_shared<APin>(otherPin, other);

    _pins.insert(std::make_pair(pin, std::move(input)));
}

std::shared_ptr<nts::IPin> nts::AComponent::getLink(std::size_t pin) const
{
    if (_pins.find(pin) != _pins.end())
        return _pins.at(pin);
    return dummy_pin;
}
