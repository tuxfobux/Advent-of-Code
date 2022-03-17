#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> data;
vector<vector<char>> data2;

int adjacent(vector<vector<char>> &data, int row, int chr) {
  int sum = 0;
  (row != 0) && (data[row - 1][chr] == '#') ? sum++ : sum += 0;
  (row != data.size() - 1) && (data[row + 1][chr] == '#') ? sum++ : sum += 0;
  (chr != 0) && (data[row][chr - 1] == '#') ? sum++ : sum += 0;
  (chr != data[0].size() - 1) && (data[row][chr + 1] == '#') ? sum++ : sum += 0;
  (row != 0) && (chr != 0) && (data[row - 1][chr - 1] == '#') ? sum++ : sum += 0;
  (row != data.size() - 1) && (chr != 0) && (data[row + 1][chr - 1] == '#') ? sum++ : sum += 0;
  (row != data.size() - 1) && (chr != data[0].size() - 1) && (data[row + 1][chr + 1] == '#') ? sum++ : sum += 0;
  (row != 0) && (chr != data[0].size() - 1) && (data[row - 1][chr + 1] == '#') ? sum++ : sum += 0;
  return sum;
}

void round_two() {
  for (int row = 0; row < data2.size(); ++row) {
    for (int chr = 0; chr < data2[row].size(); ++chr) {
      if (data2[row][chr] == '#') {
        if (adjacent(data2, row, chr) >= 4)
          data[row][chr] = 'L';
        else
          data[row][chr] = '#';
      } else
        data[row][chr] = data2[row][chr];
    }
  }
}

void round_one() {
  for (int row = 0; row < data.size(); ++row) {
    for (int chr = 0; chr < data[row].size(); ++chr) {
      if (data[row][chr] == 'L') {
        if (adjacent(data, row, chr) == 0)
          data2[row][chr] = '#';
        else
          data2[row][chr] = 'L';
      } else
        data2[row][chr] = data[row][chr];
    }
  }
}

void input() {
  ifstream ifs;
  ifs.open("input.txt");
  while (1) {
    string input;
    getline(ifs, input);
    if (input == "")
      break;
    vector<char> temp;
    vector<char> temp2;
    for (auto c : input) {
      temp.push_back(c);
      temp2.push_back('.');
    }
    data.push_back(temp);
    data2.push_back(temp2);
  }
  ifs.close();
}

int main() {
  input();
  while (data != data2) {
    round_one(); // data -> data2
    round_two(); // data2 -> data
  }
  int sum = 0;
  for (auto a : data) {
    for (auto b : a) {
      if (b == '#')
        sum++;
    }
  }
  cout << sum;
  return 0;
}
