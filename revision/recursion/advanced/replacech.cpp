#include <iostream>

using namespace std;

void replaceCh(char ch[], char key){
    if(ch[0] == '\0'){
        return;
    }
    if(ch[0] == key){
        ch[0] = 'x';
    }
    replaceCh(ch+1, key);
}

int main(){

    char input[] = "abacad";
    char key = 'a';
    replaceCh(input, key);
    cout << input;
    return 0;
}