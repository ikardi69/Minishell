# Minishell

> As beautiful as a shell

A minimal implementation of a Unix shell, inspired by Bash. This project recreates core shell functionality including command execution, pipes, redirections, environment variable management, and signal handling.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Operators and Syntax](#operators-and-syntax)
- [Signal Handling](#signal-handling)
- [Technical Implementation](#technical-implementation)
- [Project Requirements](#project-requirements)

## About

Minishell is a 42 School project that challenges students to build their own command-line interpreter. This implementation provides a functional shell environment that can execute commands, handle pipes and redirections, manage environment variables, and respond to signals just like bash.

## Features

### Core Functionality

- **Interactive Prompt**: Displays a prompt while waiting for user input
- **Command History**: Full command history navigation using arrow keys
- **Executable Search**: Locates and launches executables based on the PATH variable or absolute/relative paths
- **Quote Handling**: 
  - Single quotes (`'`) prevent interpretation of all metacharacters
  - Double quotes (`"`) prevent interpretation of metacharacters except `$`
- **Environment Variables**: Expands `$VARIABLE` to their values
- **Exit Status**: `$?` expands to the exit status of the last executed command

### Redirections

- `<` - Redirect input from a file
- `>` - Redirect output to a file (overwrite)
- `<<` - Here-document: read input until delimiter is encountered
- `>>` - Redirect output to a file (append mode)

### Pipes

- `|` - Connect the output of one command to the input of the next command
- Support for multiple pipes in a single command line

### Signal Handling

- `ctrl-C` - Displays a new prompt on a new line (does not exit the shell)
- `ctrl-D` - Exits the shell
- `ctrl-\` - Does nothing (ignored)

## Installation

### Prerequisites

- GCC compiler
- GNU Make
- readline library

### Building the Project

```bash
# Clone the repository
git clone https://github.com/ikardi69/Minishell.git
cd Minishell

# Compile the project
make

# Clean object files
make clean

# Remove all compiled files
make fclean

# Recompile everything
make re
```

## Usage

### Starting the Shell

```bash
./minishell
```

### Basic Examples

```bash
# Simple command execution
minishell$ ls -la

# Using pipes
minishell$ cat file.txt | grep "search" | wc -l

# Input/Output redirection
minishell$ cat < input.txt > output.txt

# Append to file
minishell$ echo "new line" >> file.txt

# Here-document
minishell$ cat << EOF
> line 1
> line 2
> EOF

# Environment variables
minishell$ echo $HOME
minishell$ echo $PATH

# Exit status
minishell$ ls non_existent_file
minishell$ echo $?
```

## Built-in Commands

Minishell implements the following built-in commands:

### echo

Prints arguments to standard output.

```bash
minishell$ echo Hello World
Hello World

minishell$ echo -n "No newline"
No newline minishell$
```

**Options:**
- `-n` - Do not output the trailing newline

### cd

Changes the current working directory.

```bash
minishell$ cd /path/to/directory
minishell$ cd ..
minishell$ cd ~
```

**Accepts:**
- Relative paths
- Absolute paths

### pwd

Prints the current working directory.

```bash
minishell$ pwd
/home/user/current/directory
```

### export

Sets environment variables.

```bash
minishell$ export VAR=value
minishell$ export PATH=/new/path:$PATH
```

### unset

Removes environment variables.

```bash
minishell$ unset VAR
```

### env

Displays all environment variables.

```bash
minishell$ env
HOME=/home/user
PATH=/usr/bin:/bin
...
```

### exit

Exits the shell.

```bash
minishell$ exit
minishell$ exit 42
```

## Operators and Syntax

### Quotes

- **Single quotes** (`'`): Preserve the literal value of all characters
  ```bash
  minishell$ echo '$HOME'
  $HOME
  ```

- **Double quotes** (`"`): Preserve literal value except for `$`
  ```bash
  minishell$ echo "$HOME"
  /home/user
  ```

### Special Variables

- `$?` - Exit status of the last executed command
- `$VARIABLE` - Value of environment variable VARIABLE

### Pipes

Chain multiple commands together:

```bash
minishell$ command1 | command2 | command3
```

### Redirections

- **Input**: `command < file`
- **Output**: `command > file`
- **Append**: `command >> file`
- **Here-document**: `command << DELIMITER`

## Signal Handling

In interactive mode:

| Signal | Behavior |
|--------|----------|
| `ctrl-C` | Interrupts current input, displays new prompt on new line |
| `ctrl-D` | Exits the shell (EOF) |
| `ctrl-\` | Ignored (does nothing) |

## Technical Implementation

### Allowed Functions

This project uses only the following external functions:

- **I/O**: `readline`, `printf`, `write`, `read`, `open`, `close`
- **Process Management**: `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `execve`, `exit`
- **Signal Handling**: `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`
- **File/Directory**: `access`, `stat`, `lstat`, `fstat`, `unlink`, `opendir`, `readdir`, `closedir`
- **Terminal**: `isatty`, `ttyname`, `ttyslot`, `ioctl`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`
- **Pipes/Redirection**: `dup`, `dup2`, `pipe`
- **System**: `getcwd`, `chdir`, `getenv`, `strerror`, `perror`
- **Memory**: `malloc`, `free`
- **History**: `add_history`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`

### Memory Management

- All heap-allocated memory is properly freed
- No memory leaks (excluding known readline leaks)
- Proper error handling to prevent segmentation faults and undefined behavior

### Global Variables

Limited to one global variable used exclusively for signal handling, following the project constraints.

## Project Requirements

### Compilation

```bash
make        # Compiles the project with -Wall -Wextra -Werror flags
```

### Norms

- Written in C
- Follows the 42 Norm coding standard
- No forbidden functions used
- Proper Makefile with all required rules

### Testing

The project has been tested against bash behavior for compatibility and correctness.

## Author

Created as part of the 42 School curriculum.

## License

This project is part of 42 School's educational program.