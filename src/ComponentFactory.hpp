/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** IComponentFactory
*/

#pragma once

#include "IComponent.hpp"

namespace nts {
    class ComponentFactory{
        public:
            ComponentFactory() = default;
            ~ComponentFactory() =  default;
            std::unique_ptr<IComponent> createComponent(const std::string &type);

        protected:
        private:
    };
}
