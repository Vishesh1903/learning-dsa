#include <iostream>

using namespace std;
template <typename T, typename V = int> // Used for reusing the code for different types creating generic class

class Pair {
  T x;
  V y;

public:
  void setX(T x){
    this->x = x;
  }
  void setY(V y){
    this->y = y;
  }
  T getX(){
    return x;
  }
  V getY(){
    return y;
  }
};


int main() {

  Pair<int, Pair<int, int>> p1;
  p1.setX(10);
  Pair<int, int> p2;
  p2.setX(20);
  p2.setY(30);
  p1.setY(p2);
  cout << p1.getX() << endl;
  cout << p1.getY().getX() << endl;
  cout << p1.getY().getY() << endl;

  return 0;
}