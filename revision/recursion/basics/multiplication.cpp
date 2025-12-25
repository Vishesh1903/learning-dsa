#include <iostream>

using namespace std;

int multiply(int n, int m){
    if(m == 0 || n == 0){
        return 0;
    }
    if(m == 1){
        return n;
    }
    if(n == 1){
        return m;
    }
    if(m > n){
        return m + multiply(m, n - 1); 
    }else{
        return n + multiply(n, m - 1);
    }
}

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    int result = multiply(n,m);
    cout << result << endl;

    return 0;
}