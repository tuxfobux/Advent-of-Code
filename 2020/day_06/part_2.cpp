#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_group(vector<string> &group) {
  for (int e = 0; e < group.size(); ++e) {
  }
  int temp = 0;
  for (char b = 'a'; b <= 'z'; ++b) {
    for (int c = 0; c < group.size(); ++c) {
      if (group[c].find(b) == string::npos) {
        break;
      }
      if (c == group.size() - 1) {
        temp++;
      }
    }
  }
  return temp;
}

int main() {
  ifstream ifs;
  ifs.open("input.txt");
  vector<string> group;
  int sum = 0;
  while (ifs) {
    string a;
    getline(ifs, a);
    if (a == "") {
      sum += count_group(group);
      group.clear();
      continue;
    }
    group.push_back(a);
  }
  ifs.close();
  cout << sum;
  return 0;
}
