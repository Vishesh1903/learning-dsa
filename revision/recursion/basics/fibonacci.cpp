#include <iostream>

using namespace std;


int fibNterm(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int smallAns1 = fibNterm(n-1) + fibNterm(n-2);
    return fibNterm(n-1) + fibNterm(n-2);
}

void printFibUptoN(int n, int i = 1){
   if(i > n){
    return;
   }
   cout << fibNterm(i) << " ";
   printFibUptoN(n, i+1);
}
int main(){

    int n;

    cout << "Enter the term number (n) to find the nth Fibonacci number: ";
    cin >> n;

    cout << "Fibonacci number at term " << n << " is " << fibNterm(n) << endl;

    cout << "Fibnoacci sequence of " << n << " terms is " << endl;
    printFibUptoN(n);
    return 0;
}