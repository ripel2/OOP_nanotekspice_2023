/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent()
{
}

nts::OutputComponent::OutputComponent(const std::string &name) : nts::InputComponent(),  _name(name), _outputs()
{
    _outputs[1] = nts::UNDEFINED;
}

nts::OutputComponent::~OutputComponent()
{
}

void nts::OutputComponent::dump() const
{
    std::cout << "OutputComponent" << std::endl;
}

nts::OutputComponent &nts::OutputComponent::operator=(const nts::OutputComponent &other)
{
    if(this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_name = other._name;
    return *this;
}



