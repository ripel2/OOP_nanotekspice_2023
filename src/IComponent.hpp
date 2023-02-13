/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** IComponent
*/

#pragma once

#include <iostream>

#include "Tristate.hpp"
#include "IPin.hpp"

#include <memory>

namespace nts {
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        protected:
        private:
    };
}
