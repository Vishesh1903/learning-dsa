#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string s, int n, int low, int high)
{
    if (low >= high)
    {
        return true;
    }
    if (s[low] != s[high])
    {
        return false;
    }
    return checkPalindrome(s, n, low + 1, high - 1);
}

int main()
{
    string s = "dada";
    int n = s.length();
    int low = 0;
    int high = n - 1;
    bool is_palindrome = checkPalindrome(s, n, low, high);
    if (is_palindrome)
    {
        cout << "String is a palindrome" << endl;
    }
    else
    {
        cout << "String is not a palindrome" << endl;
    }
    return 0;
}