## ex00: Easy find
Description:
- Create a function template that accepts type T and takes 2 parameters
	- type T (container)
	- integer
- the function finds the first occurrence of the second parameter in the first parameter

Purpose:
- learn how to create function that takes a template container as one of its variables.
- learn the different types of containers: vector, deque, list, 
- understand how iterator works

Key Learnings:
- function templates allow writing algorithms that work with any compatible
  container type.
- STL containers are accessed through iterators, not indices.
- STL provides algorithms such as std::find
- not all containers support indexing [], use std::distance(begin, iterator)


## Build and Run:
```
Build and run the main program:
make
./bin/easyfind [log level]

Run unit tests: (log mode set at compiler time)
> make tests
> ./bin/test_runner

Debug mode with logging:
> make debug
> ./bin/easyfind_debug [log level]
```
---
## ex01: Span
Description:
Implement a Span class that stores up to N integers (N set in the constructor).

Capacity control:
 - addNumber() adds a single integer; adding more than N elements throws an exception.
 - shortestSpan() → smallest difference between two stored numbers.
 - longestSpan() → largest difference between two stored numbers.

Purpose:
 - Working with containers
 - Managing capacity safely
 - Using STL algorithms
 - Algorithmic efficiency
	- To compute the smallest difference between any two numbers efficiently:
		- Sort the container - O(n log n)
		- Compare adjacent elements only - single pass to compute differences O(n)
		- overall complexity O(n log n) - the larger the n the slower it becomes
  	- To compute longest span use std::min_element / std::max_element
   		- each pass is O(n), O(n) + O(n) = O(n)

Key learnings:
 - Promote values to a larger type (e.g., long) before subtraction, then cast back
   to avoid overflow when computing differences.
 - STL algorithms: Use algorithms like std::sort to compute spans efficiently.

## Build and Run:
```
Build and run the main program:
make
./bin/span [log level]

Debug mode with logging:
> make debug
> ./bin/span_debug [log level]
```
---
## ex02: Muted abomination
Description:
- make a class template Array that inherits from std::stack that allows its
  member features to use iterator functions.

Key Learnings:
 - stack takes 2 parameters
	- element type
	- container type, if not specified it is defaulted to deque
 - it has a portected member _Sequence c, the underlying container
	- typedef to contianer_type
 	- source: gcc/libstdc++-v3/include/bits/stl_stack.h
 - iterators:
	- begin() or rbegin() begin is the first position
	- end() or rend() brings us to one position pas the last element
	- using keyword const is enough to be able to overload begin() and rbegin()
      no need to use cbegin() or crbegin()
 - c++ style loops use iterators to traverse
	- not all contianers have access to indexing, notably std::list, using std::distance
	  allows a more general type to work with all container types

```
Build and run the main program:
make
./bin/mutant [log level]

Run unit tests: (log mode set at compiler time)
> make tests
> ./bin/test_runner

Debug mode with logging:
> make debug
> ./bin/mutant_debug [log level]
```
