/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "APin.hpp"

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::shared_ptr<APin> input = std::make_shared<APin>(otherPin, other);
    std::shared_ptr<APin> output = std::make_shared<APin>(pin, *this);

    _inputs.insert(std::make_pair(pin, std::move(input)));
    _outputs.insert(std::make_pair(otherPin, std::move(output)));
}

std::shared_ptr<nts::IPin> nts::AComponent::getLink(std::size_t pin) const
{
    if (_inputs.find(pin) != _inputs.end())
        return _inputs.at(pin);
    if (_outputs.find(pin) != _outputs.end())
        return _outputs.at(pin);
    return nullptr;
}
