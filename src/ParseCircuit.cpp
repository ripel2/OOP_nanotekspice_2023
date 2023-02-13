/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ParseCircuit
*/

#include "Circuit.hpp"
std::string ReadStandardOutput(char *filename);

void nts::ParseCircuit(nts::Circuit &circuit, char *filename)
{
    (void)circuit;
    std::string fileContent = ReadStandardOutput(filename);
    std::cout << fileContent;
}
