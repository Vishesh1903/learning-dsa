#include <iostream>

using namespace std;

void swapTwoNum1(int &a, int &b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

void swapTwoNum2(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void swapTwoNum3(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int a = 5, b = 3;

  cout << "Before swapping: " << a << " " << b << endl;
  swapTwoNum1(a, b);
  cout << "After swapping: " << a << " " << b << endl;
  swapTwoNum2(a, b);
  cout << "After swapping: " << a << " " << b << endl;
  swapTwoNum3(a, b);
  cout << "After swapping: " << a << " " << b << endl;

  return 0;
}