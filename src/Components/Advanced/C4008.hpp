/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4008
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class C4008 : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
        protected:
        private:
    };
}