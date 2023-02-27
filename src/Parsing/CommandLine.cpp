/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** CommandLine
*/

#include "CommandLine.hpp"

#include "InputComponent.hpp"

/**
 * @brief Constructor of the CommandLine class
 * @param circuit The circuit to use
*/
nts::CommandLine::CommandLine(Circuit &circuit)
    : _circuit(circuit)
{

}

/**
 * @brief Destructor of the CommandLine class
*/
nts::CommandLine::~CommandLine()
{

}

/**
 * @brief Checks if a line is the exit command
 * @param line The line to check
 * @returns True if the line is the exit command, false otherwise
*/
bool nts::CommandLine::isExit(const std::string &line)
{
    return line == "exit";
}

/**
 * @brief Checks if a line is the display command
 * @param line The line to check
 * @returns True if the line is the display command, false otherwise
*/
bool nts::CommandLine::isDisplay(const std::string &line)
{
    return line == "display";
}

/**
 * @brief Checks if a line is the simulate command
 * @param line The line to check
 * @returns True if the line is the simulate command, false otherwise
*/
bool nts::CommandLine::isSimulate(const std::string &line)
{
    return line == "simulate";
}

/**
 * @brief Checks if a line is the loop command
 * @param line The line to check
 * @returns True if the line is the loop command, false otherwise
*/
bool nts::CommandLine::isLoop(const std::string &line)
{
    return line == "loop";
}

/**
 * @brief Checks if a line is a possible input and processes it if it is
 * @param line The line to process
*/
void nts::CommandLine::processPossibleInput(const std::string &line)
{
    std::string name;
    std::string value;

    if (line.find('=') == std::string::npos)
        return;
    name = line.substr(0, line.find('='));
    value = line.substr(line.find('=') + 1);
    if (value == "0")
        _circuit.setInput(name, nts::Tristate::FALSE);
    else if (value == "1")
        _circuit.setInput(name, nts::Tristate::TRUE);
    else if (value == "U")
        _circuit.setInput(name, nts::Tristate::UNDEFINED);
}

/**
 * @brief Processes a line of the command line
 * @param line The line to process
*/
void nts::CommandLine::processLine(const std::string &line)
{
    if (isDisplay(line))
        _circuit.display();
    else if (isSimulate(line))
        _circuit.simulate(_circuit.getTick());
    else if (isLoop(line))
        _circuit.loop();
    processPossibleInput(line);
}

/**
 * @brief Starts the command line loop
*/
void nts::CommandLine::loop()
{
    std::string line;

    std::cout << "> ";
    while (std::getline(std::cin, line)) {
        if (isExit(line))
            break;
        processLine(line);
        std::cout << "> ";
    }
}