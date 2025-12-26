#include <iostream>

using namespace std;

void removeConsecutive(char ch[]){
    if(ch[0] == '\0'){
        return;
    }
    if(ch[0] == ch[1]){
        for (int i = 0; ch[i] != '\0'; i++){
            ch[i] = ch[i + 1];
        }
        return removeConsecutive(ch);
    }
    return removeConsecutive(ch + 1);
}

int main(){

    char input[] = "aaabvvvvaacaaaaaaad";
    removeConsecutive(input);
    cout << input;
    return 0;
}