# Insecure Function

This exercise explores how we can overflow a buffer to manipulate how a function behaves. We have a program named `function_overflow` which is a simple guessing game. When you run the program with a command line argument, it compares the argument you provide against a list of words. If your input matches one of the words on the list, then you have guessed the secret word.

The challenge here is to guess the secret word without guessing the secret word. 

The `function_overflow` program is a trivial program with two functions. The main function calls the function `InsecureFunction()` which is the target of our investigation. The program is re-produced below with line numbers for reference.

```c++
   1  #include <cstring>
   2  #include <iostream>
   3  
   4  using namespace std;
   5  
   6  /// The function compares \p incoming_buffer to an internal list
   7  /// of secret words.
   8  /// \param incoming_buffer A C string
   9  /// \returns flag == 1 if the \p incoming_buffer matches a
  10  /// secret word.
  11  int InsecureFunction(char* incoming_buffer){
  12       // Note that the size of buffer is not shared with the function.
  13       int flag = 0;
  14       char tmp_buffer[16];
  15  
  16       strcpy(tmp_buffer, incoming_buffer);
  17  
  18       if(strcmp(tmp_buffer, "cat") == 0){
  19            flag = 1;
  20       }else if(strcmp(tmp_buffer, "dog") == 0){
  21            flag = 1;
  22       }
  23       return flag;
  24  }
  25  
  26  /// Demonstration program which calls an insecure function passing
  27  /// argv[1] to the function.
  28  int main(int argc, char *argv[]) {
  29    if (argc < 2) {
  30      cout << "Please provide an argument.\n";
  31      return 1;
  32    }
  33    if(InsecureFunction(argv[1])){
  34       cout << "You guessed a secret word!\n";
  35    }else{
  36       cout << "You didn't guess a secret word. Sorry.\n";
  37    }
  38    return 0;
  39  }
```

Note that `argv[1]` is passed to `InsecureFunction()`. From there, it is copied to `tmp_buffer`. Then `tmp_buffer` is compared to the two secret words `cat` and `dog`. If it matches, `flag` is set to 1. Otherwise, `flag` remains set to 0. Ultimately, `flag` is returned to the caller and the caller uses the returned `flag` to print a message congratulating the successful guess or not.

Using [`gdb`](https://en.wikipedia.org/wiki/GNU_Debugger), set a breakpoint in your program and carefully step through the program. Using your knowledge from the previous exercise, can you construct an input to the program which would cause it to believe you entered a valid secret word?

Your approach should not require you to change any of the code. A carefully constructed input is sufficient to be rewarded with a message that you guessed a secret word.

Once you have completed these steps, take note of the results. There is a graded quiz on Canvas to verify your results after you have completed all the programming in this assignment.

