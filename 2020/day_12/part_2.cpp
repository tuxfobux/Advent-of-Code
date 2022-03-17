#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void rotate(int num, int &waypoint_eawe, int &waypoint_noso) {
  int temp_eawe = waypoint_eawe;
  int temp_noso = waypoint_noso;
  switch (num) {
  case 90:
    waypoint_eawe = waypoint_noso;
    waypoint_noso = -temp_eawe;
    break;
  case 180:
    waypoint_eawe = -waypoint_eawe;
    waypoint_noso = -waypoint_noso;
    break;
  case 270:
    waypoint_eawe = -waypoint_noso;
    waypoint_noso = temp_eawe;
    break;
  }
}

int main() {
  int waypoint_noso = 1;
  int waypoint_eawe = 10;
  int ship_noso = 0;
  int ship_eawe = 0;
  ifstream ifs;
  ifs.open("input.txt");
  while (ifs) {
    string action;
    getline(ifs, action);
    if (!ifs) {
      break;
    }
    int num = stoi(action.substr(1));
    switch (action[0]) {
    case 'N':
      waypoint_noso += num;
      break;
    case 'S':
      waypoint_noso -= num;
      break;
    case 'E':
      waypoint_eawe += num;
      break;
    case 'W':
      waypoint_eawe -= num;
      break;
    case 'L':
      rotate(360 - num, waypoint_eawe, waypoint_noso);
      break;
    case 'R':
      rotate(num, waypoint_eawe, waypoint_noso);
      break;
    case 'F':
      ship_noso += num * waypoint_noso;
      ship_eawe += num * waypoint_eawe;
      break;
    }
  }
  ifs.close();
  cout << abs(ship_eawe) + abs(ship_noso);
  return 0;
}
