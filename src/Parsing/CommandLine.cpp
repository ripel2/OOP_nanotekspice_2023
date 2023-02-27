/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** CommandLine
*/

#include "CommandLine.hpp"

#include "InputComponent.hpp"

nts::CommandLine::CommandLine(Circuit &circuit) : _circuit(circuit)
{

}

nts::CommandLine::~CommandLine()
{

}

bool nts::CommandLine::isExit(const std::string &line)
{
    return line == "exit";
}

bool nts::CommandLine::isDisplay(const std::string &line)
{
    return line == "display";
}

bool nts::CommandLine::isSimulate(const std::string &line)
{
    return line == "simulate";
}

bool nts::CommandLine::isLoop(const std::string &line)
{
    return line == "loop";
}

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