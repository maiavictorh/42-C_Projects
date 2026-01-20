*This project has been created as part of the 42 curriculum by victode-.*

# push_swap

**push_swap** is an algorithmic project from the 42 curriculum that focuses on sorting a list of integers using two stacks and a restricted set of operations.

The program receives a sequence of unique integers as input and outputs the smallest possible sequence of stack operations required to sort them in ascending order.  
Only two stacks (`a` and `b`) are allowed, and all sorting must be done using predefined operations such as swaps, pushes, and rotations.

The main challenge of this project is not only to sort correctly, but to **optimize the number of operations**, encouraging careful algorithm design, complexity analysis, and efficient data manipulation in C.

---

## Instructions

#### Requirements:
- GNU `make`
- `cc` compiler
- Unix-like environment (Linux or macOS)

#### Compilation:
To compile the project, run:
```bash
make
```
This will generate the executable:
```bash
./push_swap
```

#### Usage:
Run the program by passing a list of integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
The program will output a list of instructions (one per line) that, when executed, sort the stack.

### Error Handling
If no arguments are provided, the program outputs nothing. And if an error occurs (non-integer values, duplicates, overflow, invalid input), the program outputs:
```bash
Error
```
to standard error.

---

## Algorithm Overview

### The project uses:
* A linked-list based stack implementation
* Input validation and parsing
* Indexing of values to simplify comparisons
* Specialized handling for small stack sizes
* An optimized sorting strategy for larger inputs focused on minimizing operations

### The solution is designed to respect:
* No global variables
* Proper memory management
* The 42 Norm
* Benchmark limits defined by the subject

### Resources

#### Algorithm & Data Structures:
* https://42-cursus.gitbook.io/guide
* https://en.wikipedia.org/wiki/Big_O_notation
* Book: C Programming language by Luis Damas

#### push_swap Specific:
* 42 push_swap subject PDF
* Community discussions and peer reviews at 42
* https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/

---

### AI Usage Disclosure

**AI tools were used strictly as learning support, in compliance with 42 guidelines:**
* Clarifying algorithmic concepts (e.g. complexity, bitwise logic)
* Explaining edge cases and debugging strategies
* Helping reason about data structures and optimization approaches
**All code was written, reviewed, and fully understood by the author, and no AI-generated code was copied blindly into the project.**
