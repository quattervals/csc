[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Linux Builds](https://github.com/quattervals/ese/actions/workflows/cmake.yml/build_and_test.svg)](https://github.com/quattervals/ese/actions/workflows/build_and_test.yml )

# ESE-Conference sample code: Testing microcontroller FW in C

- Code under test in C
- Test Doubles with FFF
- Testing Framework is google test

Demo of techniques how to split convoluted C-code in logical libraries.
- spying
- stubbing
- faking

## Prerequisites
```
sudo apt install build-essential gcc pkg-config cmake
```

## Compile and Run
Configure: `cmake -B build`

Build: ` cmake --build build`
- Tests are run after every build

Run tests: `ctest --test-dir build`
