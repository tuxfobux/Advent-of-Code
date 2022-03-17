#include <fstream>
#include <iostream>
#include <string>

using namespace std;

long int solve(string (&map)[323], int r, int d) {
  int solution = 0;
  int n = 0;
  for (int a = 0; a < 323; ++a) {
    if (map[a][n % 31] == '#') {
      solution++;
    }
    n += r;
    a += d - 1;
  }
  return solution;
}

int main() {
  ifstream ifs;
  string map[323];
  ifs.open("input.txt");
  for (int a = 0; a < 323; ++a) {
    ifs >> map[a];
  }
  ifs.close();
  cout << solve(map, 1, 1) * solve(map, 3, 1) * solve(map, 5, 1) *
              solve(map, 7, 1) * solve(map, 1, 2);
  return 0;
}
