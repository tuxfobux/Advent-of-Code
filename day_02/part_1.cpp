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
    int temp = 0;
    for (int b = 0; b < pass.length(); ++b) {
      if (pass[b] == lett[0]) {
        temp++;
      }
    }
    string val1 = num.substr(0, num.find('-'));
    string val2 = num.substr(num.find('-') + 1, num.length());
    if (temp >= stoi(val1) && temp <= stoi(val2)) {
      solution++;
    }
  }
  ifs.close();
  cout << solution;
  return 0;
}
