/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4512 component
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class C4512 : public AComponent {
        public:
            C4512();
            ~C4512() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
        protected:
        private:
            nts::Tristate _out_data;
            int getOutputAddress();
    };
}
