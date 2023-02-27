/*
** EPITECH PROJECT, 2023
** bsnanotekspice [WSL : Ubuntu]
** File description:
** Tristate
*/

#include "Tristate.hpp"

/**
 * @brief And operator for two Tristates
 * @param a First Tristate
 * @param b Second Tristate
 * @returns the result of the and operation between the two Tristates
*/
nts::Tristate nts::operator&(nts::Tristate a, nts::Tristate b)
{
    if (a == FALSE && b == 0)
        return FALSE;
    if (a == FALSE && b == TRUE)
        return FALSE;
    if (a == FALSE && b == UNDEFINED)
        return FALSE;
    if (a == TRUE && b == FALSE)
        return FALSE;
    if (a == TRUE && b == TRUE)
        return TRUE;
    if (a == TRUE && b == UNDEFINED)
        return UNDEFINED;
    if (a == UNDEFINED && b == FALSE)
        return FALSE;
    if (a == UNDEFINED && b == TRUE)
        return UNDEFINED;
    return UNDEFINED;
}

/**
 * @brief Or operator for two Tristates
 * @param a First Tristate
 * @param b Second Tristate
 * @returns the result of the or operation between the two Tristates
*/
nts::Tristate nts::operator|(nts::Tristate a, nts::Tristate b)
{
    if (a == FALSE && b == FALSE)
        return FALSE;
    if (a == FALSE && b == TRUE)
        return TRUE;
    if (a == FALSE && b == UNDEFINED)
        return UNDEFINED;
    if (a == TRUE && b == FALSE)
        return TRUE;
    if (a == TRUE && b == TRUE)
        return TRUE;
    if (a == TRUE && b == UNDEFINED)
        return TRUE;
    if (a == UNDEFINED && b == FALSE)
        return UNDEFINED;
    if (a == UNDEFINED && b == TRUE)
        return TRUE;
    return UNDEFINED;
}

/**
 * @brief Not operator for a Tristate
 * @param a Tristate
 * @returns the result of the not operation on the Tristate
*/
nts::Tristate nts::operator!(nts::Tristate a)
{
    if (a == UNDEFINED)
        return UNDEFINED;
    if (a == TRUE)
        return FALSE;
    return TRUE;
}

/**
 * @brief Xor operator for two Tristates
 * @param a First Tristate
 * @param b Second Tristate
 * @returns the result of the xor operation between the two Tristates
*/
nts::Tristate nts::operator^(nts::Tristate a, nts::Tristate b)
{
    if (a == UNDEFINED ||
    b == UNDEFINED)
        return UNDEFINED;
    if (a == TRUE &&
    b == TRUE)
        return FALSE;
    if (a == FALSE &&
    b == FALSE)
        return FALSE;
    return TRUE;
}

/**
 * @brief Output operator for a Tristate
 * @param s The output stream
 * @param a The Tristate to print
 * @returns the updated output stream
*/
std::ostream &nts::operator<<(std::ostream &s, nts::Tristate a)
{
    if (a == UNDEFINED)
        s << "U";
    else if (a == TRUE)
        s << "1";
    else
        s << "0";
    return s;
}
