/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include "Circuit.hpp"

namespace nts {    
    class Parser {
        public:
            Parser(Circuit &circuit, const std::string &filename);
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

            class SyntaxError : public ParserException {
                public:
                    SyntaxError(const std::string &message) : ParserException(message) {}
            };
            class UnknownComponent : public ParserException {
                public:
                    UnknownComponent(const std::string &message) : ParserException(message) {}
            };
            class NoChipset : public ParserException {
                public:
                    NoChipset(const std::string &message) : ParserException(message) {}
            };
        protected:
        private:
            Circuit &_circuit;
            std::string _filename;
    };
}
