/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** DummyPin
*/

#pragma once

#include "IPin.hpp"

namespace nts {
    class DummyPin : public IPin {
        public:
            DummyPin() = default;
            ~DummyPin() override = default;
            nts::Tristate compute() override;

        protected:
        private:
    };
}
