#include <iostream>

using namespace std;

int towerOfHanoi(int n){
    if(n == 0){
        return 0;
    }
    return towerOfHanoi(n - 1) + 1 + towerOfHanoi(n - 1);
}

void printSteps(int n, char s, char d, char h){
    if(n == 0){
        return;
    }
    printSteps(n - 1, s, h, d);
    cout << s << " -> " << d << endl;
    printSteps(n - 1, h, d, s);
}

int main(){
    int n = 64;
    cout << "Total Steps: - " << towerOfHanoi(n) << endl;
    printSteps(n, 'A', 'C', 'B');
    return 0;
}