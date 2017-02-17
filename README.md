# libft
Useful functions for C program

[![Build Status](https://travis-ci.org/anouvel/libunit.svg?branch=master)](https://travis-ci.org/anouvel/libunit)

## Architecture

The purpose of this project is to build a standard library with a test framework.

```shell
# the sources for the standard library
Makefile
srcs
incs

# the test framework sources
framework

# some stuff to check the framework behavior
tests

# the standard library tests
real-tests
```

## Usage

```shell
# compile the standard library
make

# call the framework makefile, compile the framework tests, and run them
make test-framework

# compile the standard library, call the framework makefile, compile the tests, and run them
make test
```
