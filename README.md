# MyContainer – A Custom Generic Container with Multiple Iteration Orders

### 📦 Overview

**MyContainer** is a generic C++ container class that supports dynamic storage of comparable elements with multiple custom iteration strategies. It was developed as an academic project to demonstrate advanced C++ programming techniques including templates, iterators, exception handling, and unit testing with [doctest](https://github.com/doctest/doctest).

---

### ✅ Features

- Generic container for any comparable type (e.g. `int`, `std::string`, `double`)
- Dynamic insertion and removal of elements (including duplicates)
- Bounds-checked indexing (`operator[]`)
- Exception safety for invalid accesses and removals
- Copy constructor and assignment support
- Multiple custom iterator classes:
  - `AscendingOrder` – from smallest to largest
  - `DescendingOrder` – from largest to smallest
  - `SideCrossOrder` – alternating min/max elements
  - `ReverseOrder` – reverse of insertion order
  - `Order` – original insertion order
  - `MiddleOutOrder` – from middle outward

---

### 📁 File Structure

```
.
├── Demo.cpp            # Demonstrates usage and iterators
├── test.cpp            # Unit tests using doctest
├── MyContainer.hpp     # Main implementation of MyContainer
├── doctest.hpp         # Single-header test framework (doctest)
├── Makefile            # Build instructions
```

---

### 🛠️ Build Instructions

#### Requirements
- A C++17-compatible compiler (e.g. `g++`, `clang++`)
- GNU Make

#### To build the demo and test:
```bash
make all
```

#### To run the demo:
```bash
./demo_bin
```

#### To run the unit tests:
```bash
./test_bin
```

#### To clean build artifacts:
```bash
make clean
```

---

### 🧪 Testing

The test suite (`test.cpp`) covers:

- Basic container operations (add, remove, index, size, etc.)
- Exception safety for invalid operations
- All iteration strategies, including on:
  - Empty container
  - Single element
  - Multiple elements
- Copy constructor and assignment operator

Tests are written using the [doctest](https://github.com/doctest/doctest) framework.

---

### 📸 Demo Output (Sample)

```
=== MyContainer Demo ===
Original  : [7, 15, 6, 1, 2]
Size      : 5

=== Iterator Tests ===
Ascending : 1 2 6 7 15
Descending: 15 7 6 2 1
SideCross : 1 15 2 7 6
Reverse   : 2 1 6 15 7
Order     : 7 15 6 1 2
MiddleOut : 6 15 1 7 2

=== remove(7) ===
Before : [7, 15, 6, 1, 2, 7]
After  : [15, 6, 1, 2]

=== String Container ===
["hello", "world", "cpp", "programming"]
Ascending : cpp hello programming world

=== Double Container ===
[3.14, 2.71, 1.41, 9.81]
Descending: 9.81 3.14 2.71 1.41
```

---

### 📬 Author

**Liad Haim**  
liadi.haim@gmail.com

---

### 📄 License

This project is intended for educational use only. All rights reserved to the author.

---
``` 
