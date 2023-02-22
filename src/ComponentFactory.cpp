/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** IComponentFactory
*/

#include "ComponentFactory.hpp"

#include "TrueComponent.hpp"
#include "FalseComponent.hpp"

#include "InputComponent.hpp"
#include "OutputComponent.hpp"

#include "AndComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"
#include "NotComponent.hpp"

#include <vector>

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type) {
    std::string components[] = {
        "input", "output", "clock", "true", "false",
        "and", "or", "xor", "not",
        "4001", "4011", "4030", "4069", "4071", "4081", "4008", "4013", "4017",
        "4040", "4094", "4512", "4514", "4801", "2716",
        "logger"
    };
    std::unique_ptr<nts::IComponent> (nts::ComponentFactory::*functions[])() = {
        &nts::ComponentFactory::createInput, &nts::ComponentFactory::createOutput,
        &nts::ComponentFactory::createClock, &nts::ComponentFactory::createTrue,
        &nts::ComponentFactory::createFalse,
        &nts::ComponentFactory::createAndGate, &nts::ComponentFactory::createOrGate,
        &nts::ComponentFactory::createXorGate, &nts::ComponentFactory::createNotGate,
        &nts::ComponentFactory::create4001Gate, &nts::ComponentFactory::create4011Gate,
        &nts::ComponentFactory::create4030Gate, &nts::ComponentFactory::create4069Gate,
        &nts::ComponentFactory::create4071Gate, &nts::ComponentFactory::create4081Gate,
        &nts::ComponentFactory::create4008Gate, &nts::ComponentFactory::create4013Gate,
        &nts::ComponentFactory::create4017Gate,
        &nts::ComponentFactory::create4040Gate, &nts::ComponentFactory::create4094Gate,
        &nts::ComponentFactory::create4512Gate, &nts::ComponentFactory::create4514Gate,
        &nts::ComponentFactory::create4801Gate, &nts::ComponentFactory::create2716Gate,
        &nts::ComponentFactory::createLogger
    };
    for (size_t c = 0; c < sizeof(components) / sizeof(components[0]); c++) {
        if (components[c] == type)
            return (this->*functions[c])();
    }
    throw UnknownComponent("Unknown component type " + type);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createInput() {
    return std::make_unique<nts::InputComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOutput() {
    return std::make_unique<nts::OutputComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createClock() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createTrue() {
    return std::make_unique<nts::TrueComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createFalse() {
    return std::make_unique<nts::FalseComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createAndGate() {
    return std::make_unique<nts::AndComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOrGate() {
    return std::make_unique<nts::OrComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createXorGate() {
    return std::make_unique<nts::XorComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createNotGate() {
    return std::make_unique<nts::NotComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4001Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4011Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4030Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4069Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4071Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4081Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4008Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4013Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4017Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4040Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4094Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4512Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4514Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4801Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create2716Gate() {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createLogger() {
    return nullptr;
}
