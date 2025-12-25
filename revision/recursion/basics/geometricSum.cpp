#include <iostream>

using namespace std;

double pow(double num, int n){
    if(n == 0 || num == 1){
        return 1;
    }
    return num * pow(num, n - 1);
}

double gpSum(double a, double r, int n){
    if(n == 1 || r == 0 || a == 0){
        return a;
    }
    double smallAns = gpSum(a * r, r, n - 1);
    return a + smallAns;
}

double gpSum2(double a, double r, int n, int i = 1){
    if(i > n){
        return 0;
    }
    double smallAns = gpSum2(a * r, r, n, i + 1);
    return a + smallAns;
}

int main(){
    double num, r;
    int n;
    cin >> num >> r >> n;

    cout << "Sum of the gp" << " is "<< gpSum(num, r, n) << endl;
    return 0;
}