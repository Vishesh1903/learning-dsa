#include <iostream>
#include <string>

using namespace std;


bool checkPalindrome(string str, int s, int e){
    if(s >= e){
        return true;
    }
    if(str[s] == str[e]){
        return checkPalindrome(str, s + 1, e - 1);
    }
    return false;

}

int main(){
    const string str = "abvvba";
    const int length = str.length();
    bool result = checkPalindrome(str, 0, length - 1);
    if(result){
        cout << "Is Palindrome" << endl;
    }else{
        cout << "Not Palindrome" << endl;
    }

    return 0;
}