/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OrComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}
