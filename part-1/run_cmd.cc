// Cesar Gutierrez
// CPSC 353-02
// 2022-07-26
// cesarg7@csu.fullerton.edu
// @cesar-gz
//
// Lab 02-01
//
// This is an exercise in detecting buffer overflow.
//

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/// Given the number \p n_repeat, repeat the string \p s that many
/// times and return it as a new string.
/// \param n_repeat The number of times to repeat the string \p s
/// \param s The string to repeat, must be 1 byte or larger.
/// \returns the string \p s repeated \p n_repeat times
string BigString(int n_repeat, const string& s) {
  string newString;

  for (int i = 0; i < n_repeat; i++) {
    newString = newString + s;
    if (int(newString.size()) >= n_repeat) {
      break;
    }
  }

  return string(newString);
}

/// Entry point to the test harness which repeated executes the
/// program provided as an argument with arguments that increase in
/// length. Reports when the target program exits with an abnormal
/// return code.
int main(int argc, char const* argv[]) {
  if (argc < 2) {
    cout << "Provide two arguments. The first is the command to run."
            "The second is the string to repeat.\n";
    return 1;
  }

  string base_cmd = string(argv[1]);
  string base_str = string(argv[2]);
  int rv = 0;
  // int n_repeat = 0;
  int n_repeat = base_str.size();
  while (true) {
    string repeated = BigString(n_repeat, base_str);
    // Concatenate the command and the repeated string as a
    // single string. Redirect all output to /dev/null to run
    // the program silently. We are only interested in when
    // the target program fails.
    string cmd = base_cmd + " " + repeated + " > /dev/null";
    // cout << "Running the command: " << cmd << "\n";
    cout << "Trying " << repeated.size() << " bytes. ";
    rv = system(cmd.c_str());
    cout << "Exited with status " << rv << "\n";
    if (rv > 0) {
      cout << "Segmentation fault occurred with " << repeated.size()
           << " bytes. \n";
      return 0;
    }
    n_repeat = int(n_repeat + base_str.size());
  }
}