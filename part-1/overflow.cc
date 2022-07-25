#include <cstring>
#include <iostream>

using namespace std;

/// Demonstration program which has three variables defined. The
/// first argument is copied into the second buffer and an overflow
/// condition is observed. The program print diagnostic messages to
/// help visualize what is happening within the program's memory.
int main(int argc, char *argv[]) {
  const size_t buffer_size = 8;
  int int_var = 5;
  char buffer_one[buffer_size];
  char buffer_two[buffer_size];

  if (argc < 2) {
    cout << "Please provide an argument.\n";
    return 1;
  }

  // copy a string into each buffer
  strcpy(buffer_one, "one");
  strcpy(buffer_two, "two");

  cout << "Let's see where each buffer is located and what is stored in each "
          "buffer.\n";
  cout << "buffer_one is at " << &buffer_one << ", is " << buffer_size
       << " bytes large, and contains \'" << buffer_one << "\'\n";
  cout << "buffer_two is at " << &buffer_two << ", is " << buffer_size
       << " bytes large,  and contains \'" << buffer_two << "\'\n";
  cout << "int_var is at " << &int_var << " and has the value " << int_var
       << " (0x" << hex << int_var << dec << ")\n\n";

  cout << "In memory, the order is buffer_two, buffer_one, and int_var.\n";
  cout << "The order in which they are declared in the file makes a "
          "difference.\n";
  cout << "Look at the memory addresses to verify.\n";

  cout << "argv[1] is \'" << argv[1] << "\'\n\n";

  cout << "Copying argv[1]'s " << strlen(argv[1])
       << " bytes into buffer_two.\n\n";

  strcpy(buffer_two, argv[1]);

  cout << "buffer_one is at " << &buffer_one << ", is " << buffer_size
       << " bytes large, and contains \'" << buffer_one << "\'\n";
  cout << "buffer_two is at " << &buffer_two << ", is " << buffer_size
       << " bytes large,  and contains \'" << buffer_two << "\'\n";
  cout << "int_var is at " << &int_var << " and has the value " << int_var
       << " (0x" << hex << int_var << dec << ")\n";

  return 0;
}