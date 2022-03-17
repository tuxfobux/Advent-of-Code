#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream ifs;
  int solution = 0;
  int n = 0;
  ifs.open("input.txt");
  for (int a = 0; a < 323; ++a) {
    string inp;
    ifs >> inp;
    if (inp[n % 31] == '#') {
      solution++;
    }
    n += 3;
  }
  ifs.close();
  cout << solution;
  return 0;
}
