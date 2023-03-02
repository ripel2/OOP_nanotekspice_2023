/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4040
*/

#include "C4040.hpp"

/**
 * @brief C4040 component constructor
*/
nts::C4040::C4040()
    : _lastClock(UNDEFINED), _counter(-1)
{

}

/**
 * @brief Simulates a tick of the C4040 gate
 * @param tick The current tick
*/
void nts::C4040::simulate(std::size_t tick)
{
    (void)tick;
    if (getLink(11)->compute() == TRUE) {
        _counter = 0;
        return;
    }
    if (_counter != -1 && _lastClock == TRUE && getLink(10)->compute() == FALSE) {
        _counter++;
    }
    _lastClock = getLink(10)->compute();
    if (_counter > 4095)
        _counter = 0;
}

/**
 * @brief Computes the value of the C4040 gate
 * @param pin The pin to compute
 * @returns The value of the pin
*/
nts::Tristate nts::C4040::compute(std::size_t pin)
{
    std::bitset<12> bitset(_counter);
    std::size_t pinOut[12] = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
    std::size_t pinIndex = 0;

    if (_counter == -1)
        return UNDEFINED;
    while (pinIndex < 12) {
        if (pinOut[pinIndex] == pin)
            return (bitset[pinIndex] == 1 ? TRUE : FALSE);
        pinIndex++;
    }
    return UNDEFINED;
}
