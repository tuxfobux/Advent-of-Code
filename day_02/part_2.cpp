#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream ifs;
  int solution = 0;
  ifs.open("input.txt");
  for (int a = 0; a < 1000; ++a) {
    string num, lett, pass;
    ifs >> num >> lett >> pass;
    char val1 = pass[stoi(num.substr(0, num.find('-'))) - 1];
    char val2 = pass[stoi(num.substr(num.find('-') + 1, num.length())) - 1];
    if (val1 == lett[0] | val2 == lett[0]) {
      if (val1 != val2) {
        solution++;
      }
    }
  }
  ifs.close();
  cout << solution;
  return 0;
}
