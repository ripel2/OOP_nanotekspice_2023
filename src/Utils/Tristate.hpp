/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** Tristate
*/

#pragma once

#include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true
    };

    Tristate operator&(Tristate a, Tristate b);
    Tristate operator|(Tristate a, Tristate b);
    Tristate operator!(Tristate a);
    Tristate operator^(Tristate a, Tristate b);

    std::ostream &operator<<(std::ostream &s, Tristate a);
}
