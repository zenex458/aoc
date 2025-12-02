// -*- compile-command: "g++ chal1.cpp && ./a.out" -*-
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int toint(string _input,bool _negation) {
  string combcomb;
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
  return 0;
}

int main() {
  vector<int> input{};
  string txt;
  int num = {50};
  int zero_count = {0};
  ifstream read("input");
  while (getline (read, txt)) {
    if (txt[0] == 'L') {
      input.push_back(toint(txt, true));
    } else if (txt[0] == 'R') {
      input.push_back(toint(txt, false));
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
