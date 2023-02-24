/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"

nts::Circuit::Circuit()
    : _tick(0), _components() 
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

void nts::Circuit::display() const
{
    std::shared_ptr<nts::IComponent> componentPtr;

    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : _components) {
        componentPtr = component.second;
        if (dynamic_cast<nts::InputComponent *>(componentPtr.get()) != nullptr) {
            std::cout << "  " << component.first << ": " << componentPtr->compute(1) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto &component : _components) {
        componentPtr = component.second;
        if (dynamic_cast<nts::OutputComponent *>(componentPtr.get()) != nullptr) {
            std::cout << "  " << component.first << ": " << componentPtr->compute(1) << std::endl;
        }
    }
}

std::size_t nts::Circuit::getTick() const
{
    return _tick;
}

void nts::Circuit::simulate(std::size_t tick)
{
    for (auto &component : _components) {
        component.second->simulate(tick);
    }
    _tick++;
}

void nts::Circuit::loop()
{
    while (true) {
        simulate(_tick);
        _tick++;
    }
}

void nts::Circuit::setInput(const std::string &name, nts::Tristate state)
{
    std::shared_ptr<nts::IComponent> componentPtr = getComponent(name);

    if (componentPtr == nullptr)
        return;
    // TODO: error handling on components that dont exist ? maybe in command line ?
    if (dynamic_cast<nts::InputComponent *>(componentPtr.get()) != nullptr) {
        dynamic_cast<nts::InputComponent *>(componentPtr.get())->setState(state);
    }
}

bool nts::Circuit::isEmpty() const
{
    return _components.empty();
}
