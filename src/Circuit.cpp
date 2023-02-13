/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::addComponent(const std::string &name, std::unique_ptr<IComponent> component)
{
    _components[name] = std::move(component);
}

std::shared_ptr<nts::IComponent> nts::Circuit::getComponent(const std::string &name) const
{
    if (_components.find(name) == _components.end())
        return nullptr;
    return _components.at(name);
}

void nts::Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::Circuit::simulate(std::size_t tick)
{
    (void)tick;
}
