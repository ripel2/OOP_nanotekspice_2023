/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** NotComponent
*/

#pragma once

#include "AComponent.hpp"
#include "Tristate.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}