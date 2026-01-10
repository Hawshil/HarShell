# POSIX Shell

A lightweight, POSIX-compliant shell implementation written in C++ that provides a robust command-line interface for Unix-like operating systems.

## Overview

This project implements a fully functional shell that interprets and executes commands, manages processes, and provides essential builtin functionality. The shell follows POSIX standards and supports command parsing, process execution, I/O redirection, and interactive command-line operations.

## Features

- **POSIX Compliance**: Adheres to POSIX shell specifications for compatibility and standardization
- **Builtin Commands**: Native implementation of `cd`, `pwd`, `echo`, `type`, and `exit`
- **External Program Execution**: Seamless execution of system binaries and external commands
- **Command Parsing**: Robust tokenization and parsing of shell commands and arguments
- **Interactive REPL**: Read-Eval-Print Loop for interactive command execution
- **Process Management**: Efficient handling of child processes using fork/exec
- **PATH Resolution**: Automatic command resolution through system PATH directories

## Technical Architecture

The shell operates through a classic REPL architecture:

1. **Read**: Accepts user input from stdin
2. **Parse**: Tokenizes input into commands and arguments
3. **Execute**: Determines command type (builtin vs external) and executes accordingly
4. **Output**: Displays results and prompts for next command

## Prerequisites

- C++17 or higher
- CMake 3.10+
- Unix-like operating system (Linux, macOS, BSD)
- GCC or Clang compiler

## Building from Source

```bash
# Clone the repository
git clone https://github.com/Hawshil/HarShell.git
cd shell

# Build using the provided script
chmod +x your_program.sh
./your_program.sh
Installation
bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Compile
make

# Install (optional)
sudo make install
Usage
Launch the shell by running the compiled binary:

bash
./shell
Example Commands
bash
$ pwd
/home/user

$ echo Hello, World!
Hello, World!

$ cd /tmp
$ pwd
/tmp

$ type echo
echo is a shell builtin

$ ls -la
# Lists directory contents using system ls command
Project Structure
text
.
├── src/
│   └── main.cpp          # Entry point and main shell loop
├── CMakeLists.txt        # Build configuration
├── your_program.sh       # Build and execution script
└── README.md

Implementation Details
Builtin Commands
Builtin commands are executed directly within the shell process without spawning child processes. This provides better performance and access to shell-internal state (like the current working directory).

External Commands
External programs are executed by:

Searching the PATH environment variable for the executable

Forking a child process

Using execve() to replace the child process with the target program

Waiting for child process completion

Development
The codebase is structured for maintainability and extensibility:

Modular command handling through function dispatch

Clean separation between builtin and external command execution

Efficient memory management with modern C++ practices

Contributing
Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

Author
Harshil Jain

Acknowledgments
Built with reference to POSIX shell specifications and Unix system programming principles.