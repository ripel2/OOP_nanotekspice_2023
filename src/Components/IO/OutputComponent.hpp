/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#pragma once

#include "InputComponent.hpp"


namespace nts {
    class OutputComponent : public AComponent {
        public:
            OutputComponent();
            OutputComponent(const std::string &name);
            ~OutputComponent();
            Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
        protected:
        private:

        protected:
        private:
    };
}