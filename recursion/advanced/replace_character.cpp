#include <iostream>

using namespace std;

void replaceChar(char ch[], char key){
    if(ch[0] == '\0'){
        return;
    }
    if(ch[0] == key){
        ch[0] = 'x';
    }
    replaceChar(ch + 1, key);
}


int main(){
    char ch[] = "abcaa";
    char key;
    cin >> key;

    replaceChar(ch, key);

    cout << ch << endl;
    return 0;
}