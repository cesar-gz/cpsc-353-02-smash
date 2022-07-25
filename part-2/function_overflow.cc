#include <cstring>
#include <iostream>

using namespace std;

/// The function compares \p incoming_buffer to an internal list
/// of secret words.
/// \param incoming_buffer A C string
/// \returns flag == 1 if the \p incoming_buffer matches a
/// secret word.
int InsecureFunction(char* incoming_buffer) {
  // Note that the size of buffer is not shared with the function.
  int flag = 0;
  char tmp_buffer[16];

  strcpy(tmp_buffer, incoming_buffer);

  if (strcmp(tmp_buffer, "cat") == 0) {
    flag = 1;
  } else if (strcmp(tmp_buffer, "dog") == 0) {
    flag = 1;
  }
  return flag;
}

/// Demonstration program which calls an insecure function passing
/// argv[1] to the function.
int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Please provide an argument.\n";
    return 1;
  }
  if (InsecureFunction(argv[1])) {
    cout << "You guessed a secret word!\n";
  } else {
    cout << "You didn't guess a secret word. Sorry.\n";
  }
  return 0;
}