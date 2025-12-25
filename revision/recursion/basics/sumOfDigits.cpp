#include <iostream>

using namespace std;

int sumOfDigits(int num){
    if(num >= 0 && num <= 9){
        return num;
    }
    return sumOfDigits(num/10) + sumOfDigits(num%10);

}

int main(){
    int num;
    cin >> num;

    cout << "Sum of the digits of " << num << " is "<< sumOfDigits(num) << endl;
    return 0;
}