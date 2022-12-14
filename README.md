# CPSC 353 - Assignment 02

This is a two part acaddemic exercise in manipulating buffers within a program to cause the programs to behave in ways they shouldn't. In order to complete these exercises you will need to use a computer with an x86 processor running a Linux operating system. (The exercises were developed with Ubuntu so any Debian based system ought to work well.)

# Instructions

Write a program for each exercise sub-directory. Each exercise subdirectory is prefixed with the string `part-`. The subdirectory contains a README.md which explains the requirements for the exercise.

Each exercise subdirectory has its own [GNUmakefile](https://en.wikipedia.org/wiki/Makefile) which you may use to build and test your progress. The GNUmakefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

To build the program use the `make` command. The GNUmakefile's default target is to build `all`. You must use the GNU version of `make` which is the default on Tuffix.

Every file that you submit must have a header. Please follow the guidelines from the course Canvas page.

Please adhere to the [Google C++ coding style](https://google.github.io/styleguide/cppguide.html).

When writing git log comments, please make them descriptive and meaningful.


# Rubric

Each exercise is worth 5 points. There is a total of 10 points possible. Your program must compile before it is graded. Submissions that do not compile shall be assigned a zero grade. Part 1

For each problem:

* Functionality (3 points): Your submission shall be assessed for the appropriate constructs and strategies to address the exercise. A program the passes the instructor's tests completely receives full marks. A program that partially passes the instructors tests receives partial-marks. A program that fails the majority or all the tests receives no marks.
* Format & Readability (2 point): Your submission shall be assessed by checking whether your code passess the style and format check, as well as how well it follows the proper naming conventions, and internal documentation guidelines. Git log messages are an integral part of how readable your project is. Failure to include a header forfeits all marks.
