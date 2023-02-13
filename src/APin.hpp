/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** APin
*/

#pragma once

#include "IPin.hpp"
#include "Tristate.hpp"
#include "IComponent.hpp"

namespace nts {
    class APin : public IPin {
        public:
            APin(std::size_t pin, nts::IComponent &component);
            virtual ~APin() = default;

            std::size_t getPin() const;
            void setPin(std::size_t pin);
            nts::IComponent &getComponent() const;
            nts::Tristate getState() const;
            void setState(nts::Tristate state);
            nts::Tristate compute() override;
        protected:
        private:
            std::size_t _pin;
            nts::IComponent &_component;
            nts::Tristate _state;
    };
}
