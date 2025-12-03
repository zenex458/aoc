// -*- compile-command: "g++ chal1.cpp && ./a.out" -*-
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int normalise_toint(string _input,bool _negation) {
  /*
  This will normalise the input. Because the dial has values from 0-99, anything over 100 includes a redudndant rotation, where the number of extra rotations is the number hundrednth collumn. So as the value is turned into an integer, the hundredth collumn is not included.
  "toint" in this case means turning "L2" to "-2" and "R4" to "4".
  Examples:
  _input = L478
  returns: -78

  _input = R958
  returns: 958

  _input = R47
  returns: 47
  */

  string comb;
  if (_negation) {
    comb = "-";
  } else {
    comb = "";
  }
  for (int i = 1; i <= _input.length()-1; i++) {
    if (_negation == true && _input.length()-1 > 2 && i == 1) {
      comb[1] = ' ';
    } else if (_negation == false && _input.length()-1 > 2 && i == 1) {
      comb[0] = ' ';
    } else {
      comb = comb + _input[i];
    }
  }
  return stoi(comb);
}

int main() {
  vector<int> input{};
  string txt;
  int num = {50};
  int zero_count = {0};
  ifstream read("input");
  while (getline (read, txt)) {
    // if the line begins with a L, then its negative
    if (txt[0] == 'L') {
      input.push_back(normalise_toint(txt, true));
    } // if the line begins with a R, then its positive
    else if (txt[0] == 'R') {
      input.push_back(normalise_toint(txt, false));
    } else {
      cout << "Undefined behaviour: somehow not L or R" << endl;
      break;
    }
  }
  read.close();
  for (int i = 0; i <= size(input)-1; i++) {
    num = num+input[i];
    if (num < 0) {
      num = 100 + num;
    } else if (num == 100 || num == 0) {
      num = 0;
      zero_count ++;
    } else if (num > 100) {
      num = num -100;
    }
  }
  cout << zero_count << endl;
  return (0);
}
