Zysh

A modern Unix shell written in C++.

«Project Status: Alpha (v0.1.0)»

Overview

Zysh is a work-in-progress Unix shell built from scratch in C++. The goal of this project is to create a modular, maintainable, and extensible shell while keeping compatibility with existing Unix concepts.

This project is currently in the early stages of development.

Current Features

- Lexer
- Token system
- Parser
- CMake build system

Planned Features

- Command execution
- Built-in commands ("cd", "exit", ...)
- Pipes ("|")
- Input/Output redirection (">", "<", ">>")
- Environment variables
- Command history
- Auto-completion
- Scripting support

Build

cmake -B build
cmake --build build

Roadmap

- [x] Lexer
- [x] Parser
- [ ] Executor
- [ ] Built-in commands
- [ ] Pipes
- [ ] Redirection
- [ ] Variables
- [ ] Command substitution

License

This project is licensed under the Mozila Public License 2.0.
