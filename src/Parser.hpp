/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <regex>

#include "Circuit.hpp"
#include "ComponentFactory.hpp"

namespace nts {    
    class Parser {
        public:
            Parser(Circuit &circuit, ComponentFactory &factory, const std::string &filename);
            ~Parser();

            void parseCircuit();

            class ParserException : public std::exception {
                public:
                    ParserException(const std::string &message) : _message(message) {}
                    ~ParserException() throw() {}
                    const char *what() const throw() { return _message.c_str(); }
                private:
                    std::string _message;
            };

            class FileException : public ParserException {
                public:
                    FileException(const std::string &message) : ParserException(message) {}
            };
            class SyntaxError : public ParserException {
                public:
                    SyntaxError(const std::string &message) : ParserException(message) {}
            };
            class NoChipset : public ParserException {
                public:
                    NoChipset(const std::string &message) : ParserException(message) {}
            };
            class EmptyCircuit : public ParserException {
                public:
                    EmptyCircuit(const std::string &message) : ParserException(message) {}
            };
            enum ParserStatus {
                Unknown = 0,
                Chipset,
                Link
            };
        protected:
        private:
            Circuit &_circuit;
            ComponentFactory &_factory;
            std::string _filename;
            int _status = ParserStatus::Unknown;
            int _lineNumber = 0;

            const std::regex _chipsetRegex = std::regex("^([a-zA-Z0-9_]+)\\s*([a-zA-Z0-9_]+)$");
            const std::regex _linkRegex = std::regex("^([a-zA-Z0-9_]+)\\s*:\\s*([0-9]+)\\s*([a-zA-Z0-9_]+)\\s*:\\s*([0-9]+)$");

            void stripComments(std::string &line);
            void stripLine(std::string &line, const std::string &seps);
            void parseLine(const std::string &line);
            void parseChipset(const std::string &line);
            void parseLink(const std::string &line);
    };
}
