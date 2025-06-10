# 📦 MyContainer — A Custom Generic Container with Iterators

This project implements a custom templated C++ container class named `MyContainer<T>`, which supports dynamic insertion and removal of elements, as well as six unique internal iterators that allow traversing the elements in different orders.

It is designed to be **generic**, **safe**, and **extendable**, and is accompanied by a comprehensive unit test suite using the [doctest](https://github.com/doctest/doctest) framework.

---

## 📁 Project Structure

| File            | Description                                                    |
|-----------------|----------------------------------------------------------------|
| `MyContainer.hpp` | Header-only implementation of the generic container and all six iterators |
| `MyContainer.cpp` | (Optional) Source file, can be empty or omitted if everything is in `.hpp` |
| `Demo.cpp`        | A demonstration file showing how to use the container and iterators |
| `test.cpp`        | Unit tests written using the `doctest` framework |
| `doctest.hpp`     | Header-only testing library (must be included locally) |
| `Makefile`        | Makefile to build and run demo/tests/valgrind |

---

## ⚙️ Build and Run

This project assumes a Unix-like environment (Linux/macOS/WSL).

### 🔨 Compile & Run the Demo

```bash
make
./demo_bin
