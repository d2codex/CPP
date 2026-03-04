## ex00: Start With a Few Functions
Description:
- Implement swap, min, and max function templates.

Purpose:
- learn how to create function templates
- practice correct syntax
- understand const correctness in C++.

Key Learnings:
- Passing by reference vs. by value:
- For complex types such as std::string, structs, or classes, passing by reference avoids unnecessary copying and improves efficiency.
- For simple types like int, float, or double, passing by value is sufficient.
- Template versatility:
  - Using templates in the testing framework allowed comparing different types in a single function, e.g., const char* with std::string.
- Overloading for specific cases:
  - Some comparisons, like pointer types (const T* vs. T*), required explicit overloads to handle const/non-const differences.

## Build and Run:
```
Build and run the main program:
make
./bin/whatever [log level]

Run unit tests: (log mode set at compiler time)
> make tests
> ./bin/test_runner

Debug mode with logging:
> make debug
> ./bin/whatever_debug [log level]
```
---
## ex01: Iter
Description: 
Implement a function template that takes 3 parameters and returns nothing.
- parameter 1: address of an array (pointer to the first element of the array)
- parameter 2: number of elements in the array
- parameter 3: function that will be called on every element of the array

Requirements:
- iter function template must work with any type of array
  - a regular function
  - a function template instantiation
- the callable must accept
  - a const reference OR
  - non-const reference

Purpose:
- Understand how template type deduction for array Elements (T)
- Observe how constness propagates automatically
- Learn how templates enforce type safety at compile time


Key learnings:
- Compiler deduces T from the array:
  - T = int -> T* = int*
  - T = const int -> T* = const int*
- Const correctness is enforced automatically
  - A function taking T& cannot be used with const T
  - A function taking const T& works in all cases
- Template functions passed as iter's 3rd argument
  - for non-template functions, compiler deduces function type automatically
  - for function templates, must explicitly specify the type
    - example: print<iter> 
- caller is repsponsible for correct array size input  
  - The array size, N, is not validated
  - Incorrect values lead to undefined behavior

## Build and Run:
```
Build and run the main program:
make
./bin/iter [log level]

Run unit tests: (log mode set at compiler time)
> make tests
> ./bin/test_runner

Debug mode with logging:
> make debug
> ./bin/iter_debug [log level]
```
---
## ex02: Array
Description:
- make a class template Array with:

Requirements:
- a constructor with no parameter that creates an empty array
- a constructor with an unsigned int n as a parameter, the number of elements
  initialized by default
- use operator new[] to allocate memory
- implement the subscript operator []
  - throws a  std::exception when it is out of bounds
- implement a member function size() that returns the number of elements in the array

Key Learnings:
- Using hybrid template to declare a class and define functions in the same file
  - good for small to medium projects
  - better readability - all in one place
  - user friendly, only one .hpp to add
- Tradeoffs
  - less flexible than with separate .tpp
  - slower compilation
  - no control over instantiation
- Without () the elements are default-initialized and may contain garbage
  `new T[n]()` value-initializes them (zero / default values).
- using operator= to copy in the copy constructor is unsafe
  - operator= calls delete[] and members can be unitialized causing UB
- For operator=
  - allocate first before deleting, to avoid dangling pointers if it fails

```
Build and run the main program:
make
./bin/array [log level]

Run unit tests: (log mode set at compiler time)
> make tests
> ./bin/test_runner

Debug mode with logging:
> make debug
> ./bin/array_debug [log level]
```
