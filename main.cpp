#include <iostream>
using namespace std;
#include "fstream"
#include "improvedArray.h"
#include "iomanip"
#include "sstream"
#include "string"

int main() {
  // The goal of this assignment is to create a program that will allow the user
  // to add, modify, remove, and replace values in an array.
  ifstream infile("A1.txt");
  string line;
  int nums[200];
  int count = 0;
  string num;

  if (infile.is_open()) {

    while (getline(infile, line)) {
      stringstream sS(line);
      while (getline(sS, num, ' ')) {

        nums[count] = stoi(num);
        count++;
      }
    }

  } else {
    cout << "Couldnt open file" << endl;
  }

  retrieveNum(80, nums, count); // we're inputed 80 and expect a return of 79
  modify( 5, 999, nums,count); // very obvious number '999' passed, at index of 5 should be 999
  addNum(17, nums, count);
  addNum(283, nums, count);
  replace_remove(5, nums, count);

  return 0;
}
