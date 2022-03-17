#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int count_group(string &group) {
  int temp = 0;
  for (char b = 'a'; b <= 'z'; ++b) {
    if (group.find(b) != string::npos) {
      temp++;
    }
  }
  return temp;
}

int main() {
  ifstream ifs;
  ifs.open("input.txt");
  string group;
  int sum = 0;
  while (ifs) {
    string a;
    getline(ifs, a);
    if (a == "") {
      sum += count_group(group);
      group = "";
    }
    group += a;
  }
  ifs.close();
  cout << sum;
  return 0;
}
