#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long long int> numbers;
  numbers.reserve(1000);
  vector<long long int> all_numbers;
  all_numbers.reserve(1000);
  long long int invalid_num;
  ifstream ifs;
  ifs.open("input.txt");
  for (int a = 0; a < 1000; ++a) {
    long long int num;
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
        invalid_num = num;
      }
      numbers.erase(numbers.begin());
    }
    numbers.push_back(num);
    all_numbers.push_back(num);
  }
  ifs.close();
  // find the set
  for (int c = 0; c < all_numbers.size(); ++c) {
    long long int sum = 0;
    for (int d = 0; d < all_numbers.size() - c; ++d) {
      if (sum == invalid_num && d != 1) {
        vector<long long int> solution;
        for (int e = 0; e < d; ++e) {
          solution.push_back(all_numbers[c + e]);
        }
        sort(solution.begin(), solution.end());
        cout << solution[0] + solution[solution.size() - 1];
        return 0;
      }
      if (sum > invalid_num) {
        break;
      }
      sum += all_numbers[d + c];
    }
  }
  return 0;
}
