/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** Circuit
*/

#pragma once

#include "IComponent.hpp"
#include <map>

namespace nts {
    class Circuit : IComponent {
        public:
            Circuit();
            ~Circuit();

            void addComponent(const std::string &name, std::unique_ptr<IComponent> component);
            std::shared_ptr<IComponent> getComponent(const std::string &name) const;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void loop();
            std::size_t getTick() const;
            void display() const;
            void setInput(const std::string &name, nts::Tristate state);
            bool isEmpty() const;
        protected:
        private:
            std::size_t _tick;
            std::map<std::string, std::shared_ptr<IComponent>> _components;
    };
}
