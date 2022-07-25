# Buffer Overflow

This exercise we explore how a program lays out its variables in memory and how we can manipulate the state of the variables by providing malformed input to our test program.

The Makefile builds two programs `overflow` and `run_cmd`. The program `overflow` is built from `overflow.cc` and `run_cmd` is built from `run_cmd.cc`.

The `overflow` program is a trivial program with only a main function. The program is re-produced below with line numbers for reference.

```c++
   1  #include <cstring>
   2  #include <iostream>
   3  
   4  using namespace std;
   5  
   6  /// Demonstration program which has three variables defined. The
   7  /// first argument is copied into the second buffer and an overflow
   8  /// condition is observed. The program print diagnostic messages to
   9  /// help visualize what is happening within the program's memory.
  10  int main(int argc, char *argv[]) {
  11    const size_t buffer_size = 8;
  12    int int_var = 5;
  13    char buffer_one[buffer_size];
  14    char buffer_two[buffer_size];
  15  
  16    if (argc < 2) {
  17      cout << "Please provide an argument.\n";
  18      return 1;
  19    }
  20  
  21    // copy a string into each buffer
  22    strcpy(buffer_one, "one");
  23    strcpy(buffer_two, "two");
  24  
  25    cout << "Let's see where each buffer is located and what is stored in each "
  26            "buffer.\n";
  27    cout << "buffer_one is at " << &buffer_one << ", is " << buffer_size
  28         << " bytes large, and contains \'" << buffer_one << "\'\n";
  29    cout << "buffer_two is at " << &buffer_two << ", is " << buffer_size
  30         << " bytes large,  and contains \'" << buffer_two << "\'\n";
  31    cout << "int_var is at " << &int_var << " and has the value " << int_var
  32         << " (0x" << hex << int_var << dec << ")\n\n";
  33  
  34    cout << "In memory, the order is buffer_two, buffer_one, and int_var.\n";
  35    cout << "The order in which they are declared in the file makes a "
  36            "difference.\n";
  37    cout << "Look at the memory addresses to verify.\n";
  38  
  39    cout << "argv[1] is \'" << argv[1] << "\'\n\n";
  40  
  41    cout << "Copying argv[1]'s " << strlen(argv[1])
  42         << " bytes into buffer_two.\n\n";
  43  
  44    strcpy(buffer_two, argv[1]);
  45  
  46    cout << "buffer_one is at " << &buffer_one << ", is " << buffer_size
  47         << " bytes large, and contains \'" << buffer_one << "\'\n";
  48    cout << "buffer_two is at " << &buffer_two << ", is " << buffer_size
  49         << " bytes large,  and contains \'" << buffer_two << "\'\n";
  50    cout << "int_var is at " << &int_var << " and has the value " << int_var
  51         << " (0x" << hex << int_var << dec << ")\n";
  52  
  53    return 0;
  54  }
```

The program declares three variables. Two of the variables are arrays and one of the variables is an integral type (just an `int`). The order in which the variables are declares matters because that is how the compiler will lay them out in memory.

The program has four blocks.

The first block is lines 16 to 23 where the arrays `one\0` and `two\0` are copied into `buffer_one` and `buffer_two` respectively.

The second block is lines 25 through 37 where the values and the memory locations of each variable is printed to the program's terminal.

The third block is lines 39 through 44 where the value of `argv[1]` is copied into `buffer_two`.

The fourth block is lines 46 through 51 where the values and the memory locations of each variable is printed to the program's terminal. This is identical to the second block of code from line 25 through 37.

Providing input that is too large to fit in `buffer_two` will cause the buffer to overflow into `buffer_one` and potentially `int_var`.

The program `run_cmd` is an unfinished program and requires that you complete it in order to complete this exercise. The program `run_cmd` is meant to be an analytical tool for you to use to discover how to manipulate `overflow`. With `run_cmd`, you will be able to run `overflow` very quickly trying different command line arguments to discover how many bytes you can enter on the command line before `overflow` has a segmentation fault (crashes).

# Completing `run_cmd`

The program `run_cmd` takes two arguments. The first is the command to run. The second is the string to repeat. The repeating string is used repeatedly as the command line argument until the target program has a segmentation fault. For example, let's imagine that the following command is given:
```
$ ./run_cmd ./overflow cat
```

Then `run_cmd` will execute the command `./overflow`. Each time `./overflow` is executed the command line argument will be repeated.

1. `./overflow cat`
1. `./overflow catcat`
1. `./overflow catcatcat`
1. `./overflow catcatcatcat`
1. `./overflow catcatcatcatcat`

The process continues until `run_cmd` detects a segmentation fault. At that point, `run_cmd` reports the length of the argument used.

Here is example output demonstrating how the program could work. (This example is made up just for demonstration purposes.)

```
$ ./run_cmd ./overflow lemonlime
Trying 9 bytes. Exited with status 0
Trying 18 bytes. Exited with status 0
Trying 27 bytes. Exited with status 0
Trying 36 bytes. Exited with status 0
Trying 45 bytes. Exited with status 0
Trying 54 bytes. Exited with status 0
Trying 63 bytes. Exited with status 0
Trying 72 bytes. Exited with status 0
Trying 81 bytes. Exited with status 0
Trying 90 bytes. Exited with status 0
Segmentation fault (core dumped)
Trying 99 bytes. Exited with status 35584
Segmentation fault occurred with 6 bytes copied.
```

The program `run_cmd` is mostly complete. You need to add the string duplication and looping to make the program complete.

# Instructions

## Step 1

Complete writing `run_cmd` given the requirements explained earlier.

## Step 2

Using `run_cmd` discover how many bytes given as input via `argv[1]` to `overflow` will cause `overflow` to have a segmentation fault.

Once you have the number of bytes, verify this by running the `overflow` command on the command line. For example, let's imagine that you discover that 100 bytes will cause `overflow` to have a segmentation fault. To test this limit, use Perl or Python to verify. For example, we can use Perl in the first example and Python in the second example to create an input of 100 letter 'A's. (You only need to choose one; Perl or Python.)

```
$ ./overflow $(perl -e 'print "A"x100')
Segmentation fault (core dumped)
$ ./overflow $(python -c "print('A'*100)")
Segmentation fault (core dumped)
```

Next try using an input that is one byte shorter. In our example, we are using 100 bytes so in your second verification step use 99 bytes.

```
$ ./overflow $(perl -e 'print "A"x99')
// prints stuff out as usual, no segmentation fault.
$ ./overflow $(python -c "print('A'*99)")
// prints stuff out as usual, no segmentation fault.
```

## Step 3

We now know that we can overflow `buffer_one` and `buffer_two` by providing too much input. Let's attempt to manipulate `int_var` to take on a special value to demonstrate that we can provide an input from the command line which gets copied into `buffer_two` yet changes `int_var` to a desired value.

Currently, the program prints to the terminal the memory address for each of the variables in question, `buffer_one`, `buffer_two`, and `int_var`. Verify that these values are correct by running the program in the [`gdb`](https://en.wikipedia.org/wiki/GNU_Debugger). Using the [`x`](https://sourceware.org/gdb/current/onlinedocs/gdb/Memory.html#index-x-_0028examine-memory_0029) and [`print`](https://sourceware.org/gdb/current/onlinedocs/gdb/Data.html#index-print) commands discover the memory addresses.

Take the difference between the memory location of `buffer_two` and `int_var`. This tells us how many bytes we need to overflow to manipulate the variable `int_var`. (You can use `gdb` as a hexadecimal calculator.)

Using Perl or Python, construct a command where you overflow the buffer by the number of bytes between `buffer_two` and `int_var` and then add the following bytes `\xef\xbe\xad\xde`.

For example, if you discover that the number of bytes between `buffer_two` and `int_var` is 101 then you could use one of the following commands to overwrite `int_var` with our special bytes.

```
$ ./overflow $(perl -e 'print "A"x101 . "\xef\xbe\xad\xde"')
// prints stuff out as usual, no segmentation fault.
$ ./overflow $(python -c "print('A'*101 + '\xef\xbe\xad\xde')")
// prints stuff out as usual, no segmentation fault.
```

Once you have completed these steps, take note of the results. There is a graded quiz on Canvas to verify your results after you have completed all the programming in this assignment.

