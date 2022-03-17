#include <bits/stdc++.h>

using namespace std;

void extract_nums(set<int> &req_nums, vector<string> &reqs) {
  for (auto a : reqs) {
    int first = stoi(a.substr(0, a.find('-')));
    int second = stoi(a.substr(a.find('-') + 1));
    while (first <= second) {
      req_nums.insert(second);
      second--;
    }
  }
}

void input(vector<string> &reqs, vector<int> &nearby) {
  ifstream ifs;
  ifs.open("input.txt");
  // rules part
  string row;
  while (1) {
    getline(ifs, row);
    if (row == "")
      break;
    string both = row.substr(row.find(':') + 2);
    reqs.push_back(both.substr(0, both.find(' ')));
    reqs.push_back(both.substr(both.find("or ") + 3));
  }
  // my nums part
  while (1) {
    getline(ifs, row);
    if (row == "")
      break;
  }
  // other nums part
  getline(ifs, row);
  while (1) {
    getline(ifs, row);
    if (row == "")
      break;
    size_t found = 0, last = 0;
    while (found != string::npos) {
      found = row.find(',', last);
      nearby.push_back(stoi(row.substr(last, found - last)));
      last = found + 1;
    }
  }
  ifs.close();
}

int main() {
  vector<string> reqs;
  set<int> req_nums;
  vector<int> nearby;
  input(reqs, nearby);
  extract_nums(req_nums, reqs);
  int sum = 0;
  for (auto b : nearby) {
    if (req_nums.find(b) == req_nums.end()) {
      sum += b;
    }
  }
  cout << sum;
  return 0;
}
