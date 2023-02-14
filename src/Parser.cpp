/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Parser
*/

#include "Parser.hpp"

nts::Parser::Parser(Circuit &circuit, const std::string &filename)
    : _circuit(circuit), _filename(filename)
{
}

nts::Parser::~Parser()
{
}

void nts::Parser::parseCircuit()
{
}
