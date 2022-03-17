#include <bits/stdc++.h>

using namespace std;

typedef unsigned long int ulint;

ulint solve(vector<ulint> order, unordered_map<ulint, ulint> last_time) {
  while (order.size() != 30000000) {
    ulint last = order.back();
    if (last_time.find(last) == last_time.end()) {
      last_time[last] = order.size() - 1;
      order.push_back(0);
    } else {
      order.push_back(order.size() - 1 - last_time[last]);
      last_time[last] = order.size() - 2;
    }
  }
  return order[30000000 - 1];
}

int main() {
  vector<ulint> order;
  order.reserve(30000000);
  unordered_map<ulint, ulint> last_time;
  ifstream ifs;
  ifs.open("input.txt");
  string input;
  ifs >> input;
  size_t found = 0, last_found = 0;
  while (found != string::npos) {
    found = input.find(',', last_found);
    int num = stoi(input.substr(last_found, found - last_found));
    last_time[num] = order.size();
    order.push_back(num);
    last_found = found + 1;
  }
  ifs.close();
  last_time.erase(order.back());
  cout << solve(order, last_time);

  return 0;
}
