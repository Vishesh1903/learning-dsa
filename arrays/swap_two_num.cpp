#include <iostream>

using namespace std;

int main(){

    int a = 5, b = 3;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    int c = 10 , d = 20;

    int temp = c;
    c = d;
    d = temp;

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    int e = 15, f = 25;

    e = e ^ f;
    f = e ^ f;
    e = e ^ f;

    cout << "e = " << e << endl;
    cout << "f = " << f << endl;


    return 0;
}