/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent() : InputComponent()
{
}

nts::ClockComponent::~ClockComponent()
{
}

void nts::ClockComponent::setClock()
{
    if (getState() == nts::TRUE)
        _outputs[1] = nts::FALSE;
    else
        _outputs[1] = nts::TRUE;
}
