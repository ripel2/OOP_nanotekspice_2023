/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent()
{
    _outputs[1] = nts::UNDEFINED;
}

nts::OutputComponent::OutputComponent(const std::string &name)
    : _name(name), _outputs()
{
    _outputs[1] = nts::UNDEFINED;
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    _outputs[1] = getLink(1)->compute();
    return _outputs[1];
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
    _outputs[1] = getLink(1)->compute();
}

void nts::OutputComponent::dump() const
{
        std::cout << "Output(s):" << _name << std::endl;
    std::cout << '\t' << _name << ": " << _outputs.at(1) << std::endl;
}
