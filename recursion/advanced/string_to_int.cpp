#include <iostream>

using namespace std;

int convertStringToInt(string s, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int num = convertStringToInt(s, n - 1);
    num = s[n - 1] - '0' + num * 10;
    return num;
}

int convertStringToIntV2(char input[], int sum = 0)
{
    if (input[0] == '\0')
    {
        return sum;
    }
    sum = sum * 10 + (input[0] - '0');
    return convertStringToIntV2(input + 1, sum);
}

int main()
{

    string s = "12345";
    int length = s.length();

    char input[] = "123456";

    int num2 = convertStringToIntV2(input);

    int num = convertStringToInt(s, length);
    cout << num2 << endl;
    return 0;
}