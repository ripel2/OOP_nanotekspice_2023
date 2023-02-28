/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4512
*/

#include "C4512.hpp"

/**
 * @brief C4512 component constructor
*/
nts::C4512::C4512()
    : _out_data(nts::UNDEFINED)
{

}

/**
 * @brief Gets the address of the output
 * @returns The address of the output
*/
int nts::C4512::getOutputAddress()
{
    nts::Tristate in_a = getLink(11)->compute();
    nts::Tristate in_b = getLink(12)->compute();
    nts::Tristate in_c = getLink(13)->compute();
    int address = 0;

    if (in_a == nts::UNDEFINED || in_b == nts::UNDEFINED || in_c == nts::UNDEFINED)
        return -1;
    if (in_a == nts::TRUE)
        address += 1;
    if (in_b == nts::TRUE)
        address += 2;
    if (in_c == nts::TRUE)
        address += 4;
    return address;
}

/**
 * @brief Simulates a tick of the C4512 gate
 * @param tick The current tick
*/
void nts::C4512::simulate(std::size_t tick)
{
    std::size_t addressPins[] = {1, 2, 3, 4, 5, 6, 7, 9};

    (void)tick;
    /* If the enable pin is set, return Undefined */
    if (getLink(15)->compute() == nts::TRUE) {
        _out_data = nts::UNDEFINED;
        return;
    }
    /* If the inhibit pin is set, return False */
    if (getLink(10)->compute() == nts::TRUE) {
        _out_data = nts::FALSE;
        return;
    }
    int address = getOutputAddress();
    if (address == -1) {
        _out_data = nts::UNDEFINED;
        return;
    }
    _out_data = getLink(addressPins[address])->compute();
}

/**
 * @brief Computes the value of the C4512 gate
 * @param pin The pin to compute
 * @returns The value of the pin
*/
nts::Tristate nts::C4512::compute(std::size_t pin)
{
    if (pin != 14)
        return nts::UNDEFINED;
    return _out_data;
}
