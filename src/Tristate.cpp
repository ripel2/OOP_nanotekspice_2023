/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** Tristate
*/

#include "Tristate.hpp"

nts::Tristate nts::operator&(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED ||
    b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::FALSE ||
    b == nts::Tristate::FALSE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}

nts::Tristate nts::operator|(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED ||
    b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE ||
    b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

nts::Tristate nts::operator!(nts::Tristate a)
{
    if (a == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}

nts::Tristate nts::operator^(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED ||
    b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE &&
    b == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    if (a == nts::Tristate::FALSE &&
    b == nts::Tristate::FALSE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}

std::ostream &nts::operator<<(std::ostream &s, nts::Tristate a)
{
    if (a == nts::Tristate::UNDEFINED)
        s << "U";
    else if (a == nts::Tristate::TRUE)
        s << "1";
    else
        s << "0";
    return s;
}