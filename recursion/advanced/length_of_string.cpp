#include <iostream>

using namespace std;

int calculateLength(char ch[])
{   
    if(ch[0] == '\0'){
        return 0;
    }
    return 1 + calculateLength(ch + 1);
}

int main()
{

    char ch[] = "abcdef";
    int length = calculateLength(ch);

    cout << "Length of the string: " << length << endl;


    return 0;
}