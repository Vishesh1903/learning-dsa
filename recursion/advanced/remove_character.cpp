#include <iostream>

using namespace std;

void replaceCharacter(char ch[], char key)
{
    if (ch[0] == '\0')
    {
        return;
    }
    if (ch[0] == key)
    {
        for (int i = 0; ch[i] != '\0'; i++)
        {
            ch[i] = ch[i + 1];
        }
        replaceCharacter(ch, key);
    }
    else
    {

        replaceCharacter(ch + 1, key);
    }
}



int main()
{

    char ch[] = "abcdaa";

    char key;
    cout << "Enter the key you want to remove: " << endl;
    cin >> key;

    replaceCharacter(ch, key);

    cout << ch << endl;
    return 0;
}