#include <iostream>
#include <string>

using namespace std;

void printFunc(string s, int length){
    if(length == 0){
        return;
    }
    printFunc(s, length - 1);
    cout << s[length-1] << "";
}
void reversePrintFunc(string s, int length){
    if(length == 0){
        return;
    }
    cout << s[length - 1] << "";
    reversePrintFunc(s, length - 1);
}
void printFunc2(string s, int length, int index = 0){
    if(index == length){
        return;
    }
    cout << s[index] << "";
    printFunc2(s, length, index + 1);
}
void reversePrintFunc2(string s, int length, int index){
    if (index < 0)
    {
        return;
    }
    cout << s[index] << "";
    reversePrintFunc2(s, length, index - 1);
}


    int main()
    {

        string s = "abc";
        int length = s.length();

        reversePrintFunc2(s, length, length - 1);

        return 0;
    }