/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** IPin
*/

#pragma once

#include <iostream>
#include "Tristate.hpp"

namespace nts {
    class IPin {
        public:
            IPin() = default;
            virtual ~IPin() = default;
            virtual nts::Tristate compute() = 0;

        protected:
        private:
    };
}
