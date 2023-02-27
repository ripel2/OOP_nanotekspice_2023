/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** DummyPin
*/

#include "DummyPin.hpp"

/**
 * Computes a dummy pin value
 * @returns The dummy pin value
*/
nts::Tristate nts::DummyPin::compute()
{
    std::cerr << "warning: dummy pin used" << std::endl;
    return nts::UNDEFINED;
}
