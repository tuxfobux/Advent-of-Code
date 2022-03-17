#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int noso = 0;
  int eawe = 0;
  int degrees = 90;
  ifstream ifs;
  ifs.open("test.txt");
  while (ifs) {
    string action;
    getline(ifs, action);
    if (!ifs) {
      break;
    }
    int num = stoi(action.substr(1));
    switch (action[0]) {
    case 'N':
      noso += num;
      break;
    case 'S':
      noso -= num;
      break;
    case 'E':
      eawe += num;
      break;
    case 'W':
      eawe -= num;
      break;
    case 'L':
      degrees += 360 - num;
      break;
    case 'R':
      degrees += num;
      break;
    case 'F':
      switch (degrees) {
      case 0:
        noso += num;
        break;
      case 90:
        eawe += num;
        break;
      case 180:
        noso -= num;
        break;
      case 270:
        eawe -= num;
        break;
      }
      break;
    }
    degrees = degrees % 360;
  }
  ifs.close();
  cout << abs(noso) + abs(eawe);
  return 0;
}
