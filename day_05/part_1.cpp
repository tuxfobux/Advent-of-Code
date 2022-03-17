#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream ifs;
  vector<int> ids;
  ids.reserve(809);
  int sol = 0;
  int sol2 = 0;
  ifs.open("input.txt");
  for (int a = 0; a < 809; ++a) {
    string pass;
    ifs >> pass;
    int min = 0;
    int max = 128;
    for (int b = 0; b < 7; ++b) {
      int half = (max - min) / 2;
      if (pass[b] == 'F') {
        max = min + half;
      }
      if (pass[b] == 'B') {
        min = min + half;
      }
      if (b == 6) {
        switch (pass[b]) {
        case 'F':
          sol = min - 1;
        case 'B':
          sol = max - 1;
        }
      }
    }
    min = 0;
    max = 8;
    for (int c = 7; c < 10; ++c) {
      int half = (max - min) / 2;
      if (pass[c] == 'L') {
        max = min + half;
      }
      if (pass[c] == 'R') {
        min = min + half;
      }
      if (c == 9) {
        switch (pass[c]) {
        case 'L':
          sol2 = min - 1;
        case 'R':
          sol2 = max - 1;
        }
      }
    }
    ids.push_back(sol * 8 + sol2);
  }
  ifs.close();
  sort(ids.begin(), ids.end());
  for (int d = 0; d < ids.size(); ++d) {
    if (ids[d] + 1 != ids[d + 1] && d + 1 != ids.size()) {
      cout << ids[d] + 1;
    }
  }
  return 0;
}
