#include <bits/stdc++.h>

using namespace std;

long long int solve(vector<int> &nums) {
  map<int, long long int> mem;
  mem[0] = 1;
  for (auto a : nums) {
    mem[a] = mem[a - 1] + mem[a - 2] + mem[a - 3];
  }
  return mem[nums.back()];
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
