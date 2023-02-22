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

nts::InputComponent::InputComponent(const std::string &name) : nts::AComponent(),  _name(name), _outputs()
{
    _outputs[1] = nts::UNDEFINED;
}


nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    (void)pin;
    return _outputs[1];
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::InputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)other;
    (void)otherPin;

    if (pin == 1)
        _outputs[1] = nts::TRUE;
    else if (pin == 2)
        _outputs[1] = nts::FALSE;
    else
        _outputs[1] = nts::UNDEFINED;
}

std::map<std::size_t, nts::Tristate> nts::InputComponent::getOutputs() const
{
    return _outputs;
}

void nts::InputComponent::dump() const
{
    std::cout << "InputComponent name: " << _name << std::endl;
    std::cout << "State: " << _outputs.at(1) << std::endl;
}

// nts::InputComponent &nts::InputComponent::operator=(const nts::InputComponent &other)
// {
//     if(this == &other)
//         return *this;
//     this->_outputs = other._outputs;
//     this->_name = other._name;
//     return *this;
// }