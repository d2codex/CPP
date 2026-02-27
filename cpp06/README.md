CPP06 – C++ Module 06

This repository contains the CPP06 module projects from the 42 curriculum.
The focus of this module is on advanced C++ concepts, including type conversion, serialization, and runtime type identification.

All exercises were implemented with an emphasis on clarity, robustness, modularity, and memory safety.

Exercises
ex00 – Scalar Conversion

Objective: Implement a program that converts a literal scalar value into char, int, float, and double, handling special cases (nan, inf, etc.) and invalid input.

Key Features in Implementation:
* Input is parsed and classified into types: char, int, float, double, or pseudo-literals.

Robust error handling: invalid inputs are marked impossible.

Special floating-point literals (nanf, +inff, -inff) are correctly handled.

Output formatting follows precise C++ rules:

Characters are printable or marked Non displayable

Floats always have f suffix

Doubles show decimal precision

Debug mode logs raw parsing and detected types for validation.

Example:

$ ./bin/convert_debug 42
Char: '*'
Int: 42
Float: 42.0f
Double: 42.0
ex01 – Serialization

Objective: Demonstrate the serialization and deserialization of a pointer to a Data structure into a raw integer (uintptr_t) and back.

Key Features in My Implementation:

Defined a simple Data struct with example fields.

serialize() converts a pointer to uintptr_t safely.

deserialize() converts uintptr_t back to a valid pointer.

Validated that the deserialized pointer points to the original object.

Demonstrates pointer arithmetic, reinterpret casting, and type safety in C++.

Example:

Data *ptr = new Data(42, "hello");
uintptr_t raw = serialize(ptr);
Data *recovered = deserialize(raw);
assert(ptr == recovered); // passes
ex02 – Identify Real Type

Objective: Identify the actual derived type of a polymorphic object at runtime using pointers or references.

Key Features in My Implementation:

Base class Base with three derived classes: A, B, C.

Randomly generates instances of the derived classes.

identify(Base* p) and identify(Base& p) use dynamic_cast to detect type.

Demonstrates runtime type identification (RTTI) and safe downcasting.

Handles references and pointer variations correctly.

Includes comprehensive test scenarios for all three types.

Example:

Base *obj = generate();
identify(obj);   // prints the actual class name: A, B, or C
identify(*obj);  // also works with reference
Compilation
make

Executables are placed in bin/.

Run each exercise separately at root directory:

./bin/scalar
./bin/serial
./bin/base
