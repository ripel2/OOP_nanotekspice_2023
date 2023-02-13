/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** AndComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}