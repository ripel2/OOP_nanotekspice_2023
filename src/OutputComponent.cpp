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

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    (void)pin;
    return _outputs[1];
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
    _outputs[1] = compute(_inputs.at(0));
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::OutputComponent::dump() const
{
        std::cout << "Output(s):" << _name << std::endl;
    std::cout << '\t' << _name << ": " << _outputs.at(1) << std::endl;
}
