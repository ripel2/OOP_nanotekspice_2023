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

namespace nts {
    std::atomic<bool> stopLoop(false);
}

/**
 * @brief Constructor of the Circuit class
*/
nts::Circuit::Circuit()
    : _tick(0), _components()
{
}

/**
 * @brief Destructor of the Circuit class
*/
nts::Circuit::~Circuit()
{
}

/**
 * @brief Adds a component to the circuit
 * @param name The name of the component
 * @param component The component
*/
void nts::Circuit::addComponent(const std::string &name, std::unique_ptr<IComponent> component)
{
    _components[name] = std::move(component);
}

/**
 * @brief Gets a component from the circuit given its name
 * @param name The name of the component
 * @returns The component
*/
std::shared_ptr<nts::IComponent> nts::Circuit::getComponent(const std::string &name) const
{
    if (_components.find(name) == _components.end())
        return nullptr;
    return _components.at(name);
}

/**
 * @brief Sets a link between a pin of the current component and a pin of another component
 * @param pin The pin of the current component
 * @param other The other component
 * @param otherPin The pin of the other component
 * @note This function is not implemented in the circuit class, as
 * the circuit class is only a container for components
*/
void nts::Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

/**
 * @brief Computes the value of a pin in the circuit
 * @param pin The pin number
 * @returns The value of the pin
 * @note This function is not implemented in the circuit class, as
 * the circuit class is only a container for components
*/
nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

/**
 * @brief Displays the circuit inputs and outputs
*/
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

/**
 * @brief Gets the current tick of the circuit
 * @returns The current tick of the circuit
*/
std::size_t nts::Circuit::getTick() const
{
    return _tick;
}

/**
 * @brief Simulates the circuit for a given tick
 * @param tick The tick to simulate
*/
void nts::Circuit::simulate(std::size_t tick)
{
    for (auto &component : _components) {
        component.second->simulate(tick);
    }
    _tick++;
}

/**
 * @brief Simulates the circuit until the program is stopped
*/
void nts::Circuit::loop()
{
    stopLoop = false;
    signal(SIGINT, [](int) { stopLoop = true; });
    while (stopLoop == false) {
        simulate(_tick);
        display();
        _tick++;
    }
    signal(SIGINT, SIG_DFL);
}

/**
 * @brief Sets the state of a component in the circuit
 * @param name The name of the component
 * @param state The state to set
*/
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

/**
 * @brief Checks if the circuit is empty
 * @returns True if the circuit is empty, false otherwise
*/
bool nts::Circuit::isEmpty() const
{
    return _components.empty();
}
