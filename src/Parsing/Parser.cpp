/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Parser
*/

#include "Parser.hpp"

/**
 * @brief Parser class constructor
*/
nts::Parser::Parser(Circuit &circuit, ComponentFactory &factory, const std::string &filename)
    : _circuit(circuit), _factory(factory), _filename(filename)
{
}

/**
 * @brief Parser class destructor
*/
nts::Parser::~Parser()
{
}

/**
 * @brief Strips the comments out of a line
 * @param line The line to strip
 * @note A comment is a character '#' followed by any character
*/
void nts::Parser::stripComments(std::string &line)
{
    size_t pos = line.find('#');

    if (pos != std::string::npos)
        line.erase(pos);
}

/**
 * @brief Strips the line of all the characters in seps
 * @param line The line to strip
 * @param seps The characters to strip
*/
void nts::Parser::stripLine(std::string &line, const std::string &seps)
{
    line.erase(line.find_last_not_of(seps) + 1);
    line.erase(0, line.find_first_not_of(seps));
}

/**
 * @brief Parses a line of the config file and calls the appropriate functions
 * @param line The line to parse
*/
void nts::Parser::parseLine(const std::string &line)
{
    std::string seps = " \t\n";
    std::string copy = line;

    stripComments(copy);
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

/**
 * @brief Parses a chipset
 * @param line The line to parse
 * @note The line must be in the form "chipset:name"
 * else, a SyntaxError exception will be thrown
*/
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

/**
 * @brief Parses a link between two components
 * @param line The line to parse
 * @note The line must be in the form "link:pin otherLink:otherPin"
 * else, a SyntaxError exception will be thrown
*/
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
        if (component == nullptr)
            throw NoChipset("No chipset \"" + link + "\" at line " + std::to_string(_lineNumber));
        if (otherComponent == nullptr)
            throw NoChipset("No chipset \"" + otherLink + "\" at line " + std::to_string(_lineNumber));
        if (link == otherLink)
            throw SyntaxError("Loop detected at line " + std::to_string(_lineNumber));
        component->setLink(pin, *otherComponent, otherPin);
        otherComponent->setLink(otherPin, *component, pin);
    } else {
        throw SyntaxError("Syntax error at line " + std::to_string(_lineNumber));
    }
}

/**
 * @brief Starts the parsing of the circuit file
*/
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
    if (_circuit.isEmpty())
        throw EmptyCircuit("No chipset found in file " + _filename);
}
