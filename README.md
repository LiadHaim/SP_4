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
