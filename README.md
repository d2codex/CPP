# CPP
🖤 C++ Modules - 42 School

This repository contains my solutions for the C++ Modules at 42 School.
The goal of these modules is to master C++ fundamentals, including:

* Object-oriented programming
* Memory management (stack vs heap)
* Proper use of the C++ standard library
* Good coding practices: const, references, constructors, destructors

## ⚙️ General rules:
Compiler flags: -Wall -Wextra -Werror -std=c++98
Modules: cpp00 → cpp09
***
# 🏁 CPP00
## 🔊 Ex00 - Megaphone

Description: Convert input strings to uppercase.
Purpose: Learn basic C++ syntax, std library, and namespaces.

Key Learnings:
* Command-line arguments (argc, argv)
* Using std::cout/std::cin and string manipulation

Build & Run:
`make`
`./megaphone`

## 📒 Ex01 - My Awesome Phonebook
Description: A simple phonebook using Contact and PhoneBook classes.
Purpose: Learn classes, constructors, and input/output handling.

Key Learnings:
* const correctness & constructor initializer lists
* Passing by reference vs by value
* Formatting output with std::setw

Build & Run:
`make`
`./phonebook`

💼 Ex02 (Optional) - The Job of Your Dreams
Description: Implement Account.cpp from a provided Account.hpp and tests.
Purpose: Learn class-wide static variables, logging, and time handling.

Key Learnings:
* Static class variables and functions
* Destructors for cleanup
* Using std::time_t and iterators

Build & Run:
`make`
`./account`

# 🏁 CPP01
## 🧟‍♂️ Ex00 - BraiiiiiiinnnzzzZ
Description: Implement a Zombie class to practice dynamic allocation.
Purpose: Learn stack vs heap, pointers, and manual memory management.

Key Learnings:
* new / delete
* Stack vs heap memory differences

Introduced Debugging mode

Build & Run:
`make`
`./zombie`

Build with debug mode:
`make debug`
`./zombie`
