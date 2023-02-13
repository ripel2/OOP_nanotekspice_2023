/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include "Tristate.hpp"
#include "IComponent.hpp"
#include "IPin.hpp"

#include <map>
#include <memory>

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent() = default;
            virtual ~AComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            void simulate(std::size_t tick) override {};
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::shared_ptr<IPin> getLink(std::size_t pin) const;
        protected:
        private:
            std::map<std::size_t, std::shared_ptr<IPin>> _inputs;
            std::map<std::size_t, std::shared_ptr<IPin>> _outputs;
    };
}
