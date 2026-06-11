# CPP09 — STL

Three exercises applying the C++ Standard Template Library with a focus on
container choice, algorithm correctness, and performance measurement.

## ex00 — BitcoinExchange

Reads a CSV database of historical Bitcoin exchange rates and evaluates an
input file of date/value pairs, printing each value multiplied by the closest
earlier exchange rate.

**Key points**
- `std::map` for ordered date storage and `upper_bound` for closest-date lookup
- Full date validation including leap year handling
- `strtod` with `errno` and `*end` checks for robust float parsing
- Per-line error recovery — bad lines print to stderr and processing continues

**Usage**
```bash
./btc input.txt
```

## ex01 — RPN

Evaluates a Reverse Polish Notation expression passed as a single command line
argument using a stack.

**Key points**
- `std::stack` backed by `std::list` (vector and deque reserved for ex02)
- Operator dispatch via switch on char
- Overflow detection using `long long` widening with explicit bounds check
- Private unimplemented canonical form — copying an RPN evaluator is meaningless

**Usage**
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## ex02 — PmergeMe

Sorts a sequence of positive integers from the command line using the
Ford-Johnson merge-insert sort algorithm, applied independently to a
`std::vector` and a `std::deque`, then reports the time each container took.

**Key points**
- Ford-Johnson algorithm with correct Jacobsthal insertion order
- Recursive merge sort on pairs by larger element preserves small/large pairing
- Jacobsthal ordering minimises binary search comparisons during pend insertion
- Oddball element (unpaired when input count is odd) inserted last into full chain
- `gettimeofday` for wall-clock timing in microseconds
- Single templated implementation covers both containers

**Usage**
```bash
./PmergeMe 3 5 9 7 4
./PmergeMe `shuf -i 1-1000 -n 100 | tr "\n" " "`
```

**Debug build** (prints pairs, chains, and Jacobsthal order)
```bash
make debug
./bin/PmergeMe_debug 3 5 9 7 4
```

## Building

```bash
make        # build
make clean  # remove objects
make fclean # remove objects and binaries
make re     # rebuild from scratch
```
