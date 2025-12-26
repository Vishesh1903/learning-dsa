#include <iostream>
using namespace std;

int convertStringToInt(char input[], int n){
    if(n == 0){
        return 0;
    }
    return 10 * convertStringToInt(input, n - 1) + int(input[n - 1] - '0');
}

int main (){
    char a[] = "12345";
    int length = sizeof(a)/sizeof(a[0]) - 1;
    int b = convertStringToInt(a, length);
    cout << b;
    return 0;
}