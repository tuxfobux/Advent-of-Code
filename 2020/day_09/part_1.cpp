#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers;
  numbers.reserve(1000);
  ifstream ifs;
  ifs.open("input.txt");
  for (int a = 0; a < 1000; ++a) {
    int num;
    ifs >> num;
    if (numbers.size() == 25) {
      bool temp = 0;
      for (int b = 0; b < numbers.size(); ++b) {
        if (find(numbers.begin(), numbers.end(), num - numbers[b]) !=
            numbers.end()) {
          temp = 1;
          break;
        }
      }
      if (temp == 0) {
        cout << num;
        return 0;
      }
      numbers.erase(numbers.begin());
    }
    numbers.push_back(num);
  }
  ifs.close();
  return 0;
}
