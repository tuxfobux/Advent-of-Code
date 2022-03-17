#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &order) {
  if (order.size() == 2020)
    return order[2019];
  int last = order[order.size() - 1];
  auto location = find(order.rbegin() + 1, order.rend(), last);
  if (location == order.rend()) {
    order.push_back(0);
    return solve(order);
  } else {
    order.push_back(abs(order.rbegin() - location));
    return solve(order);
  }
}

int main() {
  vector<int> order;
  ifstream ifs;
  ifs.open("input.txt");
  string input;
  ifs >> input;
  size_t found = 0, last_found = 0;
  while (found != string::npos) {
    found = input.find(',', last_found);
    order.push_back(stoi(input.substr(last_found, found - last_found)));
    last_found = found + 1;
  }
  ifs.close();
  cout << solve(order);
  return 0;
}
