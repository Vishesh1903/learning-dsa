#include <iostream>

using namespace std;

void printN(int n){
    if(n == 0){
        return;
    }
    printN(n - 1);
    cout << n << " ";
}
void printN2(int n, int i = 1){
    if(i > n){
        return;
    }
    cout << i << " ";
    printN2(n, i + 1);
}

int main(){
    int n;
    cout << "Enter the number of terms you want to print :-" << endl;
    cin >> n;
    printN2(n);
    return 0;
}