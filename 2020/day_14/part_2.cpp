#include <bits/stdc++.h>

using namespace std;

void remove_pair(vector<pair<long long int, long long int>> &memory,
                 long long int &found) {
  for (int b = 0; b < memory.size(); ++b) {
    if (memory[b].first == found) {
      memory.erase(memory.begin() + b);
      return;
    }
  }
}

void remove_x(vector<long long int> &addresses, string bs_string) {
  int x_pos = bs_string.find('X');
  if (x_pos == string::npos) {
    bitset<36> temp(bs_string);
    addresses.push_back(temp.to_ullong());
    return;
  }
  bs_string[x_pos] = '1';
  remove_x(addresses, bs_string);
  bs_string[x_pos] = '0';
  remove_x(addresses, bs_string);
}

void solve_mask(vector<pair<long long int, long long int>> &memory,
                vector<pair<int, int>> &cmds, string &mask) {
  for (auto pair : cmds) {
    vector<long long int> addresses;
    vector<int> x_es;
    bitset<36> bs(pair.first);
    string bs_string = bs.to_string();
    for (int a = 0; a < mask.length(); ++a) {
      if (mask[a] == '0')
        continue;
      if (mask[a] == '1') {
        bs_string[a] = '1';
        continue;
      }
      bs_string[a] = 'X';
    }
    remove_x(addresses, bs_string);
    for (auto address : addresses) {
      long long int found = 0;
      for (auto mem : memory) {
        if (mem.first == address) {
          found = mem.first;
          break;
        }
      }
      if (found == 0) {
        memory.push_back(make_pair(address, pair.second));
      } else {
        remove_pair(memory, found);
        memory.push_back(make_pair(found, pair.second));
      }
    }
  }
}

int main() {
  ifstream ifs;
  vector<pair<long long int, long long int>> memory;
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
    sum += n.second;
  }
  cout << sum;

  return 0;
}
