# 🧩 MyContainer — A Custom Generic Container with Iterators

This project implements a generic container class `MyContainer<T>` that supports insertion, deletion, index access, and various custom iterators. It is designed for types that are comparable (i.e., support `operator<` and `operator==`), and includes extensive testing and demos.

---

## 📁 Project Structure

| File              | Description |
|-------------------|-------------|
| `MyContainer.hpp` | Header file with full implementation of `MyContainer` and all its iterators (templated and header-only). |
| `MyContainer.cpp` | Empty source file, reserved for optional implementation separation. |
| `Demo.cpp`        | Demo program that prints the output of each iterator on various example containers. |
| `test.cpp`        | Comprehensive test suite using the `doctest` framework. |
| `doctest.hpp`     | The `doctest` testing framework (header-only). |
| `Makefile`        | Makefile to build and run demo/tests/valgrind with targets like `make`, `make test`, `make valgrind`. |

---

## 🚀 How to Build & Run

Ensure your system supports C++17 or later (e.g., using `g++` on Linux or WSL).

```bash
make             # Compiles Demo.cpp into ./demo_bin
./demo_bin       # Runs the demo (prints iterator outputs)

make test        # Builds and runs all tests (creates ./test_bin)

make valgrind    # Runs both demo and tests with Valgrind to detect memory leaks
🧠 MyContainer Features
✅ Generic class template (template<typename T = int>)

✅ Dynamic insertion and deletion of elements

✅ Index access with operator[]

✅ Exception handling (out-of-range, element not found)

✅ Multiple iterator types:

Iterator Type	Description
AscendingOrder	From smallest to largest
DescendingOrder	From largest to smallest
SideCrossOrder	Alternates between smallest and largest, then inward
ReverseOrder	Reverse of insertion order
Order	In insertion order
MiddleOutOrder	From middle outward, alternating sides

🔍 Example Demo Output
text
Copy
Edit
=== Iterator Tests ===
Ascending : 1 2 6 7 15 
Descending: 15 7 6 2 1 
SideCross : 1 15 2 7 6 
Reverse   : 2 1 6 15 7 
Order     : 7 15 6 1 2 
MiddleOut : 6 15 1 7 2 
✅ Unit Testing (with doctest)
The test.cpp file includes 11 test cases and 30+ assertions, covering:

Basic operations (size, add, remove, access)

Exception handling

Different element types (int, double, std::string)

All six iterator types

Edge cases: empty containers, single-element containers

Copy constructor & assignment operator

Run with:

bash
Copy
Edit
make test
🛡️ Memory Leak Detection (Valgrind)
To validate memory safety and ensure no memory leaks:

bash
Copy
Edit
make valgrind
Expected output should include:

text
Copy
Edit
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
🎓 Project Context
This project was written by a computer science undergraduate student as part of a data structures assignment.
It was designed to practice:

Templates and generic programming

Custom iterator implementations

Exception-safe memory handling

Unit testing and test-driven development

Use of tools like Valgrind and Make

👤 Author Info
Name: Liad Haim
Email: liadi.haim@gmail.com
University: Ariel University
Year: 2025

Enjoy exploring the iterators – and don’t forget to run valgrind 😉
