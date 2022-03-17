#include <bits/stdc++.h>

using namespace std;

long long int solve(int num, int rem, long long int prod) {
  long long int pp = prod / num;
  int inv = 0;
  for (int b = 1; b > 0; ++b) {
    if ((pp * b) % num == 1) {
      inv = b;
      break;
    }
  }
  return rem * pp * inv;
}

int main() {
  ifstream ifs;
  ifs.open("input.txt");
  ifs.ignore(numeric_limits<streamsize>::max(), '\n');
  string ids;
  ifs >> ids;
  char *ids2 = new char[ids.length() + 1];
  strcpy(ids2, ids.data());
  char *token = strtok(ids2, ",");
  vector<string> busses;
  while (token != NULL) {
    busses.push_back(token);
    token = strtok(NULL, ",");
  }
  ifs.close();
  vector<pair<int, int>> input;
  long long int prod = 0;
  for (int a = 0; a < busses.size(); ++a) {
    if (busses[a] == "x")
      continue;
    int temp = stoi(busses[a]);
    (prod != 0) ? prod *= temp : prod = temp;
    input.push_back(make_pair(temp, temp - a));
  }
  long long int sol = 0;
  for (auto p : input) {
    sol += solve(p.first, p.second, prod);
  }
  cout << sol % prod;
  return 0;
}
