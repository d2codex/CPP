# 🖤 C++ Modules - 42 School

This repository contains my solutions for the C++ Modules at 42 School. The goal of these modules is to master C++ fundamentals, including:

- Object-oriented programming
- Memory management (stack vs heap)
- Proper use of the C++ standard library
- Good coding practices: const, references, constructors, destructors

## ⚙️ General Rules

**Compiler flags:** `-Wall -Wextra -Werror -std=c++98`  
**Modules:** cpp00 → cpp09

---

## 📚 Module 00

### 🔊 Exercise 00 - Megaphone

**Description:** Convert input strings to uppercase.

**Purpose:** Learn basic C++ syntax, std library, and namespaces.

**Key Learnings:**
- Command-line arguments (`argc`, `argv`)
- Using `std::cout`/`std::cin` and string manipulation

**Build & Run:**
```bash
make
./megaphone
```

---

### 📒 Exercise 01 - My Awesome Phonebook

**Description:** A simple phonebook using `Contact` and `PhoneBook` classes.

**Purpose:** Learn classes, constructors, and input/output handling.

**Key Learnings:**
- Const correctness & constructor initializer lists
- Passing by reference vs by value
- Formatting output with `std::setw`

**Build & Run:**
```bash
make
./phonebook
```

---

### 💼 Exercise 02 (Optional) - The Job of Your Dreams

**Description:** Implement `Account.cpp` from a provided `Account.hpp` and tests.

**Purpose:** Learn class-wide static variables, logging, and time handling.

**Key Learnings:**
- Static class variables and functions
- Destructors for cleanup
- Using `std::time_t` and iterators

**Build & Run:**
```bash
make
./account
```

---

## 📚 Module 01

### 🧟‍♂️ Exercise 00 - BraiiiiiiinnnzzzZ

**Description:** Implement a `Zombie` class to practice dynamic allocation.

**Purpose:** Learn stack vs heap, pointers, and manual memory management.

**Key Learnings:**
- `new` / `delete` operators
- Stack vs heap memory differences
- Introduced debugging mode

**Build & Run:**
```bash
make
./zombie
```

**Build with debug mode:**
```bash
make debug
./zombie
```

### 🧠 Exercise 01 – Moar brainz!

**Description:** Create a horde of Zombies allocated dynamically using
arrays.

Purpose: Extend dynamic allocation concepts by managing multiple objects
on the heap and handling edge cases safely.

Key Learnings:
* Dynamic allocation of object arrays using new[]
* Proper deallocation with delete[]
* Validating user input before allocation
* Graceful handling of allocation failure (std::bad_alloc)
* Use of compile-time debug mode (DEBUG macro)
* Tracking object lifecycle with static class members
* Writing structured test cases using a struct
* Automating tests with loops instead of manual calls
* Defensive programming with size limits (MAX_HORDE_SIZE)

**Build & Run:**
```bash
make
./horde
```

**Build with debug mode:**
```bash
make debug
./horde
```
---

## 📝 Notes

- Each module builds upon the previous one, progressively introducing more advanced C++ concepts
- All code adheres to the 42 School norm and coding standards
- Extensive testing has been performed to ensure robust implementations

## 🤝 Contributing

This is a personal learning project, but feedback and suggestions are always welcome!

## 📄 License

This project is part of the 42 School curriculum.
