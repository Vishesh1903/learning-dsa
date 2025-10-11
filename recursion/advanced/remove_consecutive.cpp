#include <iostream>

using namespace std;

void removeConsecutiveChar(char input[]){
    if(input[0] == '\0' || input[1] == '\0'){
        return;
    }
    if(input[0] == input[1]){
        for (int i = 1; input[i] != '\0'; i++){
            input[i] = input[i + 1];
        }
        removeConsecutiveChar(input);
    }
    else{
        removeConsecutiveChar(input + 1);
    }
}

int main(){

    char input[] = "aaabbbccdda";

    removeConsecutiveChar(input);

    cout << input << endl;
    return 0;
}