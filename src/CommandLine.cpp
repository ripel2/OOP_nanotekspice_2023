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

void nts::CommandLine::processLine(const std::string &line)
{
    if (isDisplay(line))
        _circuit.display();
    else if (isSimulate(line))
        _circuit.simulate(_circuit.getTick());
    else if (isLoop(line))
        _circuit.loop();
    else if (line == "test") {
        std::shared_ptr<nts::IComponent> comp = _circuit.getComponent("in_1");
        // faire le test la
    }
    else
        throw CommandLineException("Unknown command");
    // TODO: inputs and outputs
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