/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4040 component
*/

#pragma once

#include "AComponent.hpp"

#include <bitset>

namespace nts {
    class C4040 : public AComponent {
        public:
            C4040();
            ~C4040() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
        protected:
        private:
            nts::Tristate _lastClock;
            long int _counter;
    };
}
