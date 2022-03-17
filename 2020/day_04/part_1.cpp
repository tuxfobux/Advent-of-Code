#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream ifs;
  string line, pass;
  string req[] = {"byr", "ecl", "eyr", "hcl", "hgt", "iyr", "pid"};
  int sol = 0;
  ifs.open("input.txt");
  while (ifs) {
    getline(ifs, line);
    if (line == "") {
      pass.erase(0, 1);
      for (int a = 0; a < 7; ++a) {
        if (pass.find(' ' + req[a]) == string::npos) {
          break;
        }
        if (a == 6) {
          sol++;
        }
      }
      pass = "";
    }
    pass += ' ' + line;
  }
  ifs.close();
  cout << sol + 1;
  return 0;
}
