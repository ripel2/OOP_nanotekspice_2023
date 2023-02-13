/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** FalseConponent
*/

#pragma once

#include "Tristate.hpp"
#include "AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}
