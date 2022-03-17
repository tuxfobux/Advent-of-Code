#include <bits/stdc++.h>

using namespace std;

int solve(vector<pair<string, int>> program, int &accum, int nop_jmp) {
  vector<int> used;
  int loc = 0;
  while (find(used.begin(), used.end(), loc) == used.end()) {
    if (loc == program.size())
      break;
    used.push_back(loc);
    if (loc == nop_jmp) {
      if (program[loc].first[0] == 'n') {
        program[loc].first[0] = 'j';
      } else {
        program[loc].first[0] = 'n';
      }
    }
    switch (program[loc].first[0]) {
    case 'n':
      loc += 1;
      break;
    case 'a':
      accum += program[loc].second;
      loc += 1;
      break;
    case 'j':
      loc += program[loc].second;
      break;
    }
    if (loc == 0)
      loc = 1;
  }
  if (loc == program.size() - 1)
    return 1;
  return 0;
}

void input(vector<pair<string, int>> &o_program, vector<int> &nop_jmp) {
  ifstream ifs;
  ifs.open("input.txt");
  while (ifs) {
    pair<string, int> inst;
    ifs >> inst.first >> inst.second;
    if (inst.first == "nop" | inst.first == "jmp")
      nop_jmp.push_back(o_program.size());
    o_program.push_back(inst);
  }
  ifs.close();
}

int main() {
  vector<pair<string, int>> o_program;
  vector<int> nop_jmp;
  input(o_program, nop_jmp);
  int accum = 0, res = 0, count = 0;
  while (!res) {
    accum = 0;
    if (count == nop_jmp.size())
      return 0;
    res = solve(o_program, accum, nop_jmp[count]);
    count++;
  }
  cout << accum;
  return 0;
}
