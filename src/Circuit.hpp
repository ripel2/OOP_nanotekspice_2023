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
            Circuit() = default;    
            ~Circuit() = default;

            void addComponent(const std::string &name, std::unique_ptr<IComponent> component);
            std::shared_ptr<IComponent> getComponent(const std::string &name) const;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
        protected:
        private:
            std::size_t _tick;
            std::map<std::string, std::shared_ptr<IComponent>> _components;
    };
}
