# cbrainfuck

Yet another Brainfuck compiler.

## Build

To build the project use the following commands

```bash
mkdir build
make
```

## Quick Start

There are a couple of example programs in the examples directory. You can compile them by running the following example commands

```bash
cbf -i examples/hello.bf -o hello
cbf -i examples/life.bf -o life
cbf -i examples/tictactoe.bf -o tictactoe
```

## Transpiling

You can also just transpile the program to C code by adding the corresponding flag

```bash
cbf -i examples/hello.bf -o hello.c -t
```

## Usage

```
Usage: cbf -i <input file>

Options:
  -h         Show this message
  -i <file>  Input source file
  -o <file>  Output file
  -t         Transpile only to output file
```
