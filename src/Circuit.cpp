/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"

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

