/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023
** File description:
** Main
*/

#include "Circuit.hpp"
#include "ComponentFactory.hpp"
#include "Parser.hpp"
#include "CommandLine.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " file.nts" << std::endl;
        return (84);
    }
    nts::Circuit circuit;
    nts::ComponentFactory factory;
    nts::Parser parser = nts::Parser(circuit, factory, av[1]);
    try {
        parser.parseCircuit();
    } catch (nts::Parser::ParserException &e) {
        std::cerr << av[0] << ": " << e.what() << std::endl;
        return (84);
    } catch (nts::ComponentFactory::ComponentFactoryException &e) {
        std::cerr << av[0] << ": " << e.what() << std::endl;
        return (84);
    }
    nts::CommandLine commandLine = nts::CommandLine(circuit);
    try {
        commandLine.loop();
    } catch (nts::CommandLine::CommandLineException &e) {
        std::cerr << av[0] << ": " << e.what() << std::endl;
        return (84);
    }
    return (0);
}
