#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool hcl_valid(string hcl) {
  char valid[] = {'a', 'b', 'c', 'd', 'e', 'f', '0', '1',
                  '2', '3', '4', '5', '6', '7', '8', '9'};
  if (hcl[0] != '#') {
    return false;
  }
  hcl.erase(0, 1);
  for (int i = 0; i < hcl.length(); ++i) {
    if (find(begin(valid), end(valid), hcl[i]) == end(valid)) {
      return false;
    }
  }
  return true;
}

int main() {
  ifstream ifs;
  string line, pass;
  string req[] = {"byr", "ecl", "eyr", "hcl", "hgt", "iyr", "pid"};
  int sol = 0;
  vector<string> eyes = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
  ifs.open("input.txt");
  while (ifs) {
    getline(ifs, line);
    if (line == "") {
      if (pass[1] == ' ') {
        pass.erase(0, 1);
      }
      bool invalid = true;
      for (int a = 0; a < 7; ++a) {
        if (pass.find(' ' + req[a]) == string::npos) {
          cout << pass;
          break;
        }
        switch (a) {
        case 0:
          if (stoi(pass.substr(pass.find(req[0]) + 4, 4)) >= 1920 &&
              stoi(pass.substr(pass.find(req[0]) + 4, 4)) <= 2002) {
            invalid = false;
          } else {
            invalid = true;
          }
          break;
        case 1:
          if (find(eyes.begin(), eyes.end(),
                   pass.substr(pass.find(req[1]) + 4, 3)) != eyes.end()) {
            invalid = false;
          } else {
            invalid = true;
          }
          break;
        case 2:
          if (stoi(pass.substr(pass.find(req[2]) + 4, 4)) >= 2020 &&
              stoi(pass.substr(pass.find(req[2]) + 4, 4)) <= 2030) {
            invalid = false;
          } else {
            invalid = true;
          }
          break;
        case 3:
          if (hcl_valid(pass.substr(pass.find(req[3]) + 4, 7))) {
            invalid = false;
          } else {
            invalid = true;
          }
          break;
        case 4:
          if (pass.substr(pass.find(req[4]) + 3, 2) == "in") {
            if (stoi(pass.substr(pass.find(req[4]) + 4, 2)) >= 59 &&
                stoi(pass.substr(pass.find(req[4]) + 4, 2)) <= 76) {
              invalid = false;
            } else {
              invalid = true;
            }
          }
          if (pass.substr(pass.find(req[4]) + 4, 2) == "cm") {
            if (stoi(pass.substr(pass.find(req[4]) + 4, 3)) >= 150 &&
                stoi(pass.substr(pass.find(req[4]) + 4, 3)) <= 193) {
              invalid = false;
            } else {
              invalid = true;
            }
          }
          break;
        case 5:
          if (stoi(pass.substr(pass.find(req[5]) + 4, 4)) >= 2010 &&
              stoi(pass.substr(pass.find(req[5]) + 4, 4)) <= 2020) {
            invalid = false;
          } else {
            invalid = true;
          }
          break;
        case 6:
          if (pass.find(req[6]) + 13 <= pass.length()) {
            if (pass.length() != pass.find(req[6]) + 13) {
              if (pass.substr(pass.find(req[6]) + 13, 1) != " ") {
                invalid = true;
                break;
              }
            }
            for (int b = 0; b < 9; ++b) {
              if (!isdigit(pass.substr(pass.find(req[6]) + 4, 9)[b])) {
                invalid = true;
                break;
              }
            }
            break;
          } else {
            invalid = true;
            break;
          }
        }
        if (invalid) {
          break;
        }
      }
      if (!invalid) {
        // cout << pass << "\n\n";
        sol++;
      }
      pass = "";
    }
    pass += ' ' + line;
  }
  ifs.close();
  cout << sol; // 209 too high
  return 0;
}
