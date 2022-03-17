#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums) {
  int one_diff = 0, three_diff = 1;
  int last = 0;
  for (int a = 0; a < nums.size(); ++a) {
    switch (nums[a] - last) {
    case 1:
      one_diff++;
      break;
    case 3:
      three_diff++;
      break;
    }
    last = nums[a];
  }
  return one_diff * three_diff;
}

int main() {
  vector<int> nums;
  ifstream ifs;
  ifs.open("input.txt");
  while (ifs) {
    int input;
    ifs >> input;
    nums.push_back(input);
  }
  ifs.close();
  sort(nums.begin(), nums.end());
  cout << solve(nums);

  return 0;
}
