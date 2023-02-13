/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu-20.04]
** File description:
** ReadStandardInput
*/

#include <iostream>
#include <fstream>

std::string ReadStandardOutput(char *filename)
{
    std::string line;
    std::string fileContent;
    std::ifstream file(filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            fileContent += line + "\n";
        }
        file.close();
        return fileContent;
    } else {
        std::cerr << "Unable to open file";
        exit(84);
    }
    return "";
}
