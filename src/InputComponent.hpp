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
            InputComponent(const std::string &name);
            ~InputComponent() override = default;
            Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::map<std::size_t, nts::Tristate> getOutputs() const;
            void dump() const;
        protected:
        private:
            std::string _name;
            std::map<std::size_t, nts::Tristate> _outputs;
    };
}
