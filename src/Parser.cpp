/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Parser
*/

#include "Parser.hpp"

nts::Parser::Parser(Circuit &circuit, ComponentFactory &factory, const std::string &filename)
    : _circuit(circuit), _factory(factory), _filename(filename)
{
}

nts::Parser::~Parser()
{
}

void nts::Parser::stripLine(std::string &line, const std::string &seps)
{
    line.erase(line.find_last_not_of(seps) + 1);
    line.erase(0, line.find_first_not_of(seps));
}

void nts::Parser::parseLine(const std::string &line)
{
    std::string seps = " \t\n";
    std::string copy = line;

    stripLine(copy, seps);
    if (copy.empty() || copy[0] == '#')
        return;
    if (copy.find(".chipsets:") != std::string::npos) {
        _status = ParserStatus::Chipset;
        return;
    }
    if (copy.find(".links:") != std::string::npos) {
        _status = ParserStatus::Link;
        return;
    }
    if (_status == ParserStatus::Chipset) {
        parseChipset(copy);
    } else if (_status == ParserStatus::Link) {
        parseLink(copy);
    } else {
        throw SyntaxError("Unknown section at line " + std::to_string(_lineNumber));
    }
}

void nts::Parser::parseChipset(const std::string &line)
{
    std::smatch chipsetMatch;

    if (std::regex_match(line, chipsetMatch, _chipsetRegex)) {
        std::string chipset = chipsetMatch[1];
        std::string name = chipsetMatch[2];
        std::unique_ptr<nts::IComponent> component = _factory.createComponent(chipset);
        if (component == nullptr) // TODO: remove this temporary solution. No element of the factory should be null
            throw ParserException("Debug: chipset not implemented \"" + chipset + "\" at line " + std::to_string(_lineNumber));
        _circuit.addComponent(name, std::move(component));
    } else {
        throw SyntaxError("Syntax error at line " + std::to_string(_lineNumber));
    }
}

void nts::Parser::parseLink(const std::string &line)
{
    std::smatch linkMatch;

    if (std::regex_match(line, linkMatch, _linkRegex)) {
        std::string link = linkMatch[1];
        std::size_t pin = std::stoi(linkMatch[2]);
        std::string otherLink = linkMatch[3];
        std::size_t otherPin = std::stoi(linkMatch[4]);
        std::shared_ptr <nts::IComponent> component = _circuit.getComponent(link);
        std::shared_ptr <nts::IComponent> otherComponent = _circuit.getComponent(otherLink);
        component->setLink(pin, *otherComponent, otherPin);
    } else {
        throw SyntaxError("Syntax error at line " + std::to_string(_lineNumber));
    }
}

void nts::Parser::parseCircuit()
{
    std::string line;
    std::string fileContent;
    std::ifstream file(_filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            _lineNumber++;
            parseLine(line);
        }
        file.close();
    } else {
        throw FileException(_filename + ": " + strerror(errno));
    }
}
