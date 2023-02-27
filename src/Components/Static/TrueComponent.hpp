/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** TrueComponent
*/

#pragma once

#include "Tristate.hpp"
#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}
