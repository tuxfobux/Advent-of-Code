#include <bits/stdc++.h>

using namespace std;

int solve(pair<string, int> inst, int loc, int &accum) {
  switch (inst.first[0]) {
  case 'n':
    return loc + 1;
  case 'a':
    accum += inst.second;
    return loc + 1;
  case 'j':
    return loc += inst.second;
  }
  return 1;
}

void input(vector<pair<string, int>> &program) {
  ifstream ifs;
  ifs.open("input.txt");
  while (ifs) {
    pair<string, int> inst;
    ifs >> inst.first >> inst.second;
    program.push_back(inst);
  }
  ifs.close();
}

int main() {
  vector<pair<string, int>> program;
  input(program);
  vector<int> used;
  int accum = 0, loc = 0;
  while (find(used.begin(), used.end(), loc) == used.end()) {
    used.push_back(loc);
    loc = solve(program[loc], loc, accum);
  }
  cout << accum;
  return 0;
}
