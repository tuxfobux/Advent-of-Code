#include <bits/stdc++.h>

using namespace std;

bool contains_gold(unordered_map<string, vector<string>> &data, string key) {
  vector<string> items = data.find(key)->second;
  for (auto n : items) {
    if (n.find("shiny gold") != string::npos |
        contains_gold(data, n.substr(2) + ' '))
      return 1;
  }
  return 0;
}

void split_input(unordered_map<string, vector<string>> &data, string input) {
  string key = input.substr(0, input.find("bags contain"));
  vector<string> splitted;
  if (input.find("no other bags") == string::npos) {
    string part_2 = input.substr(input.find("contain") + 7);
    size_t found = 0, last = 0;
    while (found != string::npos) {
      found = part_2.find(',', last);
      string temp = part_2.substr(last, found - last);
      splitted.push_back(temp.substr(1, temp.find("bag") - 2));
      last = found + 1;
    }
  }
  data[key] = splitted;
}

int main() {
  unordered_map<string, vector<string>> data;
  ifstream ifs;
  ifs.open("input.txt");
  while (ifs) {
    string input;
    getline(ifs, input);
    if (input != "")
      split_input(data, input);
  }
  ifs.close();
  int sum = 0;
  for (auto a : data) {
    if (a.second.size() != 0)
      sum += contains_gold(data, a.first);
  }
  cout << sum;
  return 0;
}
