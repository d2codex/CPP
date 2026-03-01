## ex00: Start With a Few Functions

Description:
Implement swap, min, and max function templates.

### Purpose:
To learn how to create function templates, practice correct syntax, and understand const correctness in C++.

### Key Learnings:
- Passing by reference vs. by value:
- For complex types such as std::string, structs, or classes, passing by reference avoids unnecessary copying and improves efficiency.
- For simple types like int, float, or double, passing by value is sufficient.
- Template versatility:
  - Using templates in the testing framework allowed comparing different types in a single function, e.g., const char* with std::string.
- Overloading for specific cases:
  - Some comparisons, like pointer types (const T* vs. T*), required explicit overloads to handle const/non-const differences.
---
## Build and Run:
```
Build and run the main program:
make
./bin/whatever [log level]

Run unit tests:
> make tests
> ./bin/test_runner [log level]

Debug mode with logging:
> make debug
> ./bin/whatever [log level]
```
