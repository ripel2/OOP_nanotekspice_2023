/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** OutputComponent
*/

#pragma once

#include "InputComponent.hpp"


namespace nts {
    class OutputComponent : public InputComponent {
        public:
            OutputComponent();
            OutputComponent(const std::string &name);
            ~OutputComponent();
            Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::map<std::size_t, nts::Tristate> getOutputs() const;
            std::map<std::size_t, nts::Tristate> getInputs() const;
            void dump() const;
        protected:
        private:
            std::string _name;
            std::map<std::size_t, nts::Tristate> _inputs;
            std::map<std::size_t, nts::Tristate> _outputs;

        protected:
        private:
    };
}