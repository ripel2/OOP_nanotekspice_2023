/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** InputComponent
*/

#pragma once

#include "IComponent.hpp"
#include "AComponent.hpp"

#include <map>
#include <memory>

namespace nts {
    class InputComponent : public AComponent {
        public:
            InputComponent();
            ~InputComponent() override = default;
            Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick);
            void setState(nts::Tristate state);
            void dump() const;
        protected:
        private:
            nts::Tristate _state = nts::UNDEFINED;
            nts::Tristate _incState = nts::UNDEFINED;
            bool _needsUpdate = false;
    };
}
