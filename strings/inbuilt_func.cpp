#include <iostream>
#include <string>
using namespace std;

bool mystrcomp(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)){
        return false;
    }
    for(int i=0; i<strlen(str1); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

void mystrNcopy(char str1[], char str2[], int n){
    for(int i=0; i<=n; i++){
        str1[i] = str2[i];
    }
}

void mystrCat(char str1[], char str2[]){
    int i = strlen(str1);
    for (int j = 0; j <= strlen(str2); j++)
    {
        str1[i + j] = str2[j];
    }
}

int main()
{

    char str1[2];
    char str2[100];
    cin>> str1 >> str2;

    cout << "String 1 : "<<str1 << endl;
    cout << "String 1 length: " << strlen(str1) << endl;
    cout << "String 2 : "<<str2 << endl;
    cout << "String 2 length: " << strlen(str2) << endl;

    // if(strcmp(str1, str2) == 0){
    //     cout << "Strings are equal" << endl;
    // } else {
    //     cout << "Strings are not equal" << endl;
    // }

    //Custom string comparison function

    // if(mystrcomp(str1, str2)){
    //     cout << "Strings are equal" << endl;
    // } else {
    //     cout << "Strings are not equal" << endl;
    // }

    //String copy
    // strcpy(str2, str1);
    // cout << "After copying, String 1 : "<<str1 << endl;
    // cout << "After copying, String 1 length: " << strlen(str1) << endl;
    // cout << "String 2 : "<<str2 << endl;
    // cout << "String 2 length: " << strlen(str2) << endl;

    //string ncopy
    // strncpy(str1, str2, 5);
    // cout << "After copying, String 1 : "<<str1 << endl;
    // cout << "After copying, String 1 length: " << strlen(str1) << endl;
    // cout << "String 2 : "<<str2 << endl;
    // cout << "String 2 length: " << strlen(str2) << endl;

    //Custom string ncopy function
    // mystrNcopy(str1, str2, strlen(str2));
    // cout << "After copying, String 1 : "<<str1 << endl;
    // cout << "After copying, String 1 length: " << strlen(str1) << endl;
    
    // cout << "String 2 : "<<str2 << endl;
    // cout << "String 2 length: " << strlen(str2) << endl;

    //Custom string concatenation function
    mystrCat(str1, str2);
    cout << "After concatenation, String 1 : "<<str1 << endl;
    cout << "After concatenation, String 1 length: " << strlen(str1) << endl;
    cout << "String 2 : "<<str2 << endl;
    cout << "String 2 length: " << strlen(str2) << endl;
    return 0;
}