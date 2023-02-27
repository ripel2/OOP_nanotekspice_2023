/*
** EPITECH PROJECT, 2023
** bsnanotekspice2 [WSL : Ubuntu]
** File description:
** AndComponent
*/

#include "AndComponent.hpp"
#include "Tristate.hpp"
#include "IPin.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::UNDEFINED;
    nts::Tristate nts1 = getLink(1)->compute();
    nts::Tristate nts2 = getLink(2)->compute();
    return nts1 & nts2;
}
