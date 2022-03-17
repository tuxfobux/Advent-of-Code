#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }

int main() {
  ifstream ifs;
  ifs.open("input.txt");
  float earliest;
  string ids;
  ifs >> earliest;
  ifs >> ids;
  char ids2[ids.length() + 1];
  strcpy(ids2, ids.c_str());
  char *token = strtok(ids2, ",");
  ifs.close();
  vector<string> busses;
  while (token != NULL) {
    busses.push_back(token);
    token = strtok(NULL, ",");
  }
  vector<pair<int, int>> results;
  for (int a = 0; a < busses.size(); ++a) {
    if (busses[a] == "x")
      continue;
    int temp = ceil(earliest / stoi(busses[a]));
    results.push_back(
        make_pair(stoi(busses[a]), temp * stoi(busses[a]) - earliest));
  }
  sort(results.begin(), results.end(), cmp);
  cout << results[0].first * results[0].second;
  return 0;
}
