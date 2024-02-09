
#include "improvedArray.h"
#include <iostream>
using namespace std;
#include "fstream"
#include "iomanip"
#include "sstream"
#include "string"
// whats below will check if the given number exists and if does then it'll return the index of the number and if it doesn't then it'll return 0
int retrieveNum(int num, int arr[], int count) {

  pair<int, int> solution;
  for (int i = 0; i < count; i++) {
    if (num == arr[i]) {
      solution.first = num;
      solution.second = i;
      cout << "num: " << solution.first << " , Located at: " << solution.second
           << endl;
      return i;
    }
  }
  cout << "not found" << endl;
  return 0;
}

// The code below should add number at the end of the array
void addNum(int number, int arr[], int &count) {
  count += 1;
  int new_arr[count];
  for (int i = 0; i < count + 1; i++) {
    new_arr[i] = arr[i];
    if (i == count - 1) {
      new_arr[i] = number;
    }
  }
  cout << "You called addNum. Below is printed list for verification. You "
          "added: "
       << number << endl;

  for (int i = 0; i < count; i++) {
    arr[i] = new_arr[i];
    cout << "Index: " << i << " Number: " << arr[i] << endl;
  }
}
// We will change the integer at the index given and return both the new and old value
pair<int, int> modify(int index, int new_val, int arr[], int count) {
  pair<int, int> solution;
  int temp_old;
  for (int i = 0; i < count; i++) {
    if (i == index) {
      temp_old = arr[i];
      arr[i] = new_val;
      cout << "old value: " << temp_old << endl;
      cout << "new value: " << arr[i] << endl;
      cout << " " << endl << endl << endl;

      solution.first = temp_old;
      solution.second = new_val;
    }
  }
 
  return solution; // The first solution is the old value and the second is the new value
}
int replace_remove(int index, int arr[], int &count) {
  int input;
  while (true) {
    cout << "would you like to remove a value or replace a value? (1) for "
            "remove, (2) for replace: "
         << endl;
    cin >> input;
    if (input == 1) {

      int temp_arr[count - 1];

      for (int i = 0; i < count; i++) {
        temp_arr[i] = arr[i];
        if (i == index) {
          for (int a = i; a < count - 1; a++) {
            temp_arr[a] = arr[i + 1];
            i += 1;
          }
        }
      }

      for (int i = 0; i < count - 1; i++) {
        arr[i] = temp_arr[i];
      }
      cout << "You called remove.Below is printed list for verification, "
              "removed at index: "
           << index << endl;
      for (int i = 0; i < count - 1; i++) {
        cout << "Index: " << i << " Element: " << arr[i] << endl;
      }

      return 1;
    } else if (input == 2) {
      // replace with 0
      for (int i = 0; i < count; i++) {
        if (i == index) {
          arr[i] = 0;
        }
      }
      cout << "You called replace.Below is the printed list for verification. "
              "Replaced with 0 at index: "
           << index << endl;
      for (int i = 0; i < count; i++) {
        cout << "Index: " << i << " Element: " << arr[i] << endl;
      }
      return 0;
    } else {
      cout << "Not valid option, try again" << endl;
    }
  }
}
