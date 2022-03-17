#include <bits/stdc++.h>

using namespace std;

int contains_gold(unordered_map<string, vector<string>> &data, string key) {
  vector<string> items = data.find(key)->second;
  int sum = 0;
  for (auto n : items) {
    sum += n[0] - '0' + ((n[0] - '0') * contains_gold(data, n.substr(2) + ' '));
  }
  return sum;
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
  cout << contains_gold(data, "shiny gold ");
  return 0;
}
