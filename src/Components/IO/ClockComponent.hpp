/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ClockComponent
*/

#pragma once

#include "InputComponent.hpp"

namespace nts {
    class ClockComponent : public InputComponent {
        public:
            ClockComponent();
            ~ClockComponent();
            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
        protected:
        private:
    };
}
