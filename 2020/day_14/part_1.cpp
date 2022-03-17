#include <bits/stdc++.h>

using namespace std;

void solve_mask(vector<unsigned long long int> &memory,
                vector<pair<int, int>> &cmds, string &mask) {
  for (auto pair : cmds) {
    bitset<35> bs(pair.second);
    for (int a = 0; a < mask.length(); ++a) {
      if (mask[a] != 'X')
        (mask[a] == '1') ? bs[35 - a] = 1 : bs[35 - a] = 0;
    }
    memory[pair.first] = bs.to_ullong();
  }
}

int main() {
  ifstream ifs;
  vector<unsigned long long int> memory(100000, 0);
  ifs.open("input.txt");
  vector<pair<int, int>> mask_part;
  string mask;
  while (ifs) {
    string input;
    getline(ifs, input);
    if (input[1] == 'a' | input == "") {
      solve_mask(memory, mask_part, mask);
      if (input != "")
        mask = input.substr(7, input.length());
      mask_part.erase(mask_part.begin(), mask_part.end());
      continue;
    }
    int address = stoi(input.substr(4, input.find(']') - 4));
    int num = stoi(input.substr(input.find('=') + 2, input.length() - 1));
    mask_part.push_back(make_pair(address, num));
  }
  ifs.close();
  // Print the sum
  long int sum = 0;
  for (auto n : memory) {
    sum += n;
  }
  cout << sum;

  return 0;
}
