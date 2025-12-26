#include <iostream>

using namespace std;

void removeCh(char ch[], char key){
    if(ch[0] == '\0'){
        return;
    }
    if(ch[0] == key){
        for (int i = 0; ch[i] != '\0'; i++){
            ch[i] = ch[i + 1];
        }
    }
    removeCh(ch + 1, key);
}

int main(){

    char input[] = "abacad";
    char key = 'a';
    removeCh(input, key);
    cout << input;
    return 0;
}