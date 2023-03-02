/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** C4008
*/

#include "C4008.hpp"

nts::Tristate sumTristate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == nts::TRUE && b == nts::TRUE)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate nts::C4008::compute(std::size_t pin)
{
    if (pin == 10) {
        return sumTristate(getLink(6)->compute(), getLink(7)->compute());
    }
    if (pin == 11) {
        nts::Tristate a = sumTristate(getLink(6)->compute(), getLink(7)->compute());
        return sumTristate(a, sumTristate(getLink(4)->compute(), getLink(5)->compute()));
    }
    if (pin == 12) {
        nts::Tristate a = sumTristate(getLink(6)->compute(), getLink(7)->compute());
        nts::Tristate b = sumTristate(a, sumTristate(getLink(4)->compute(), getLink(5)->compute()));
        return sumTristate(b, sumTristate(getLink(2)->compute(), getLink(3)->compute()));
    }
    if (pin == 13) {
        nts::Tristate a = sumTristate(getLink(6)->compute(), getLink(7)->compute());
        nts::Tristate b = sumTristate(a, sumTristate(getLink(4)->compute(), getLink(5)->compute()));
        nts::Tristate c = sumTristate(b, sumTristate(getLink(2)->compute(), getLink(3)->compute()));
        return sumTristate(c, sumTristate(getLink(1)->compute(), getLink(15)->compute()));
    }
    if (pin == 14) {
        nts::Tristate a = sumTristate(getLink(6)->compute(), getLink(7)->compute());
        nts::Tristate b = sumTristate(a, sumTristate(getLink(4)->compute(), getLink(5)->compute()));
        nts::Tristate c = sumTristate(b, sumTristate(getLink(2)->compute(), getLink(3)->compute()));
        return sumTristate(c, sumTristate(getLink(1)->compute(), getLink(15)->compute()));
    }
    return nts::UNDEFINED;
}
