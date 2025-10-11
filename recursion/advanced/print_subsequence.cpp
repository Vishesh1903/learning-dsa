#include <iostream>
#include <string>

using namespace std;

void printAllSubsequence(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    printAllSubsequence(input.substr(1), output + input[0]);
    printAllSubsequence(input.substr(1), output);
}
void printAllSubsequenceV2(char input[], char output[], int index)
{
    if (input[0] == '\0')
    {
        output[index] = '\0';
        cout << output << endl;
        return;
    }
    output[index] = input[0];
    printAllSubsequenceV2(input + 1, output, index + 1);
    printAllSubsequenceV2(input + 1, output, index);
}

int main()
{

    string input = "abcdef";
    string output = "";

    char input2[] = "abc";
    char output2[10] = "";
    // printAllSubsequence(input, output);
    printAllSubsequenceV2(input2, output2, 0);

    return 0;
}