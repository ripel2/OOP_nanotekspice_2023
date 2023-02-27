/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** IComponentFactory
*/

#pragma once

#include "IComponent.hpp"

namespace nts {
    class ComponentFactory{
        public:
            ComponentFactory() = default;
            ~ComponentFactory() =  default;
            std::unique_ptr<IComponent> createComponent(const std::string &type);

            class ComponentFactoryException : public std::exception {
                public:
                    ComponentFactoryException(const std::string &message) : _message(message) {}
                    ~ComponentFactoryException() throw() {}
                    const char *what() const throw() { return _message.c_str(); }
                private:
                    std::string _message;
            };

            class UnknownComponent : public ComponentFactoryException {
                public:
                    UnknownComponent(const std::string &message) : ComponentFactoryException(message) {}
            };
        protected:
        private:
            std::unique_ptr<IComponent> createInput();
            std::unique_ptr<IComponent> createOutput();
            std::unique_ptr<IComponent> createClock();
            std::unique_ptr<IComponent> createTrue();
            std::unique_ptr<IComponent> createFalse();
            std::unique_ptr<IComponent> createAndGate();
            std::unique_ptr<IComponent> createOrGate();
            std::unique_ptr<IComponent> createXorGate();
            std::unique_ptr<IComponent> createNotGate();
            std::unique_ptr<IComponent> create4001Gate();
            std::unique_ptr<IComponent> create4011Gate();
            std::unique_ptr<IComponent> create4030Gate();
            std::unique_ptr<IComponent> create4069Gate();
            std::unique_ptr<IComponent> create4071Gate();
            std::unique_ptr<IComponent> create4081Gate();
            std::unique_ptr<IComponent> create4008Gate();
            std::unique_ptr<IComponent> create4013Gate();
            std::unique_ptr<IComponent> create4017Gate();
            std::unique_ptr<IComponent> create4040Gate();
            std::unique_ptr<IComponent> create4094Gate();
            std::unique_ptr<IComponent> create4512Gate();
            std::unique_ptr<IComponent> create4514Gate();
            std::unique_ptr<IComponent> create4801Gate();
            std::unique_ptr<IComponent> create2716Gate();
            std::unique_ptr<IComponent> createLogger();
    };
}
