/*
** EPITECH PROJECT, 2023
** OOP_nanotekspice_2023 [WSL : Ubuntu]
** File description:
** CommandLine
*/

#pragma once

#include "Circuit.hpp"

namespace nts {
    class CommandLine {
        public:
            CommandLine(Circuit &circuit);
            ~CommandLine();

            void loop();

            class CommandLineException : public std::exception {
                public:
                    CommandLineException(const std::string &message) : _message(message) {}
                    ~CommandLineException() throw() {}
                    const char *what() const throw() { return _message.c_str(); }
                private:
                    std::string _message;
            };
        protected:
        private:
            Circuit &_circuit;

            bool isExit(const std::string &line);
            bool isDisplay(const std::string &line);
            bool isSimulate(const std::string &line);
            bool isLoop(const std::string &line);
            void processLine(const std::string &line);
            void processPossibleInput(const std::string &line);
    };
}
