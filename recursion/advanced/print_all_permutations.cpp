#include <iostream>
#include <string>

using namespace std;

void printAllPermutations(string s, int index)
{
    if (s.length() == index)
    {
        cout << s << endl;
        return;
    }
    for (int j = index; j < s.length(); j++)
    {
        swap(s[index], s[j]);
        printAllPermutations(s, index + 1);
        swap(s[index], s[j]);
    }
}

void printAllPermutationsV2(char input[], int index)
{
    if(input[index] != '\0'){
        cout << input << endl;
        return;
    }
    for (int j = index; input[j] != '\0'; j++){
        swap(input[index], input[j]);
        printAllPermutationsV2(input, index + 1);
        swap(input[index], input[j]);
    }
}

int main()
{
    string s = "abc";

    int length = s.length();

    char input[] = "abc";


    printAllPermutations(s, 0);
    printAllPermutations(input, 0);
    return 0;
}