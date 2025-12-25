#include <iostream>

using namespace std;

int countZeroes(int num){
    if(num == 0){
        return 1;
    }
    if(num/10 == 0){
        return 0;
    }
    return countZeroes(num / 10) + countZeroes(num % 10);
}

// int countZeroes(int num){
//     if(num == 0){
//         return 0;
//     }

//     int smallAns = countZeroes(num / 10);
//     int lastDigit = num%10;
//     if(lastDigit == 0){
//         return 1 + smallAns;
//     }else{
//         return smallAns;
//     }
// }

int main(){
    int num;
    cin >> num;

    cout << countZeroes(num) << endl;

    return 0;
}