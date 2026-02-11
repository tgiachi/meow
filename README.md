# meow

`meow` is a tiny `cat`-like command-line tool made to practice C.

It reads a file and prints its content to standard output.

## Why this project

This project is intentionally small, so it is useful for learning core C topics:

- command-line arguments
- basic string checks
- file I/O with `fopen`, `fgets`, and `fclose`
- simple program structure

## Usage

```bash
meow [options] <file>
```

Options:

- `-h`, `--help` show help
- `-v`, `--version` show version

Example:

```bash
./build/meow notes.txt
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Install

By default, this project installs the binary to `/usr/local/bin`.

```bash
sudo cmake --install build
```

After installation:

```bash
meow notes.txt
```

## Install with Homebrew (local formula)

Homebrew requires formulas to be installed from a tap.
From the project root:

```bash
brew tap tgiachi/meow /Users/squid/projects/meow
cp Formula/meow.rb "$(brew --repository)/Library/Taps/tgiachi/homebrew-meow/Formula/meow.rb"
brew install --HEAD --build-from-source tgiachi/meow/meow
```

Then run:

```bash
meow notes.txt
```
