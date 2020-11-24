# Simple Shell
## Description  
`Simple_shell` is a project that consists of building a simple Unix shell replica, in order to obtain a deeper appreciation of how it works. Also, as specific objectives `simple_shell` is programmed in c language, based on everything learned so far and applying linux concepts as well.

Our `simple_shell` will have the ability to:
1. Initialize: When executing our program, it remains in an infinite loop that prints a prompt and is always ready to take any command.
2. Interpret: Which means we are going to read the command, find the executable file and run it, it is not about building every command. A simpler way to see it is with these three steps
    - Read: reads the command from standard input
    - Parse: Separate the command into a program and arguments.
       - If the command belongs to a Built in (exit, env, setenv, unsetenv) this will be executed in order to our function.
    - Execute: executes the analyzed command.
3. Terminate - After your commands run, `simple_shell` executes shutdown commands, frees memory, and terminates.

## Built with 
C programming language

## File Contents
The repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
|[AUTHORS](./AUTHORS) | Contains info about authors of the project |
|[man_1_simple_shell](./man_1_simple_shell) | Man page for the created shell |
|[shell.h](./shell.h)| Header file containing all function prototypes and struct declarations |
|[main.c](./main.c) | The main function |
|[functions.c](./functions.c) | `_strdup` function, `call_strtok` function, `execute` function,  `find_path` function and `str_concat` function |
|[functions1.c](./functions1.c)| `_getenv` function, `_getposition` function, `_cexit` function,  `_atoi` function and `delspace` function |
|[functions2.c](./functions2.c)| `message_exit` function, `built_in` function, `_cenv` function,  `free_stuff` function and `argset` function |
|[functions3.c](./functions3.c)| `_unsetenv` function, `argunset` function and `handle_sigint` function |

## Usage and Installation 
1. Clone the repository 
```
$ https://github.com/torres1-23/simple_shell.git
```
2. Compile with compilation flags
- `Simple_shell` will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
3. Run the executable.
```
./hsh
```
## Running an Example
4. After running the executable the prompt appears waiting for the command.
5. The example command is ls -l, as seen in the image

<p align="center"><a href="https://ibb.co/K0q5msN"><img src="https://i.ibb.co/1vq0bXs/exampler.png" alt="exampler" border="0"></a> </p>


## Authors 

* **Mauricio Alejandro Torres** - [torres1-23](https://github.com/torres1-23)
* **Alejandra Higuera Munevar** - [Alejandra2254](https://github.com/Alejandra2254)