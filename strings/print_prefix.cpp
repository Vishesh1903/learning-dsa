#include <iostream>
#include <string>
using namespace std;

void printAllPrefixes(char str[]){
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int j = 0; j <= i; j++){
            cout << str[j];
        }
        cout << endl;
    }

}

void printAllSuffixes(char str[]){
    for (int i = strlen(str) - 1; i > 0; i--){
        for (int j = i; j <= strlen(str); j++){
            cout << str[j];
        }
        cout << endl;
    }
}

int main()
{
    char str[100];

    cin >> str;

    cout <<"String: " <<str << endl;

    printAllPrefixes(str);
    printAllSuffixes(str);

    return 0;
}