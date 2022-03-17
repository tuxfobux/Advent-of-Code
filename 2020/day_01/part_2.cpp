#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream ifs;
  vector<int> nums;
  nums.reserve(200);
  // input
  ifs.open("input.txt");
  for (int a = 0; a < 200; ++a) {
    int temp;
    ifs >> temp;
    nums.push_back(temp);
  }
  ifs.close();
  // solve
  sort(nums.begin(), nums.end());
  for (int b = 0; b < nums.size(); ++b) {
    for (int c = 0; c < nums.size(); ++c) {
      if (binary_search(nums.begin(), nums.end(), 2020 - nums[b] - nums[c]) ==
          true) {
        cout << nums[b] * nums[c] * (2020 - nums[b] - nums[c]);
        return 1;
      }
    }
  }

  return 0;
}
