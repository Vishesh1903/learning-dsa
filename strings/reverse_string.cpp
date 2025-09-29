#include <iostream>

using namespace std;

int length(char string_arr[])
{
    int count = 0;
    while (string_arr[count] != '\0')
    {
        count++;
    }
    return count;
}

void reverse(char arr[], int len)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

int main() {

    int n;
    cin >> n;
    cin.ignore(); // to ignore the newline character after integer input
    char arr[n];
    cin.getline(arr, n);

    cout<< "Original string: " << arr << endl;

    // reversing the string
    int len = length(arr);
    reverse(arr, len);
    cout << "Reversed string: " << arr << endl;
    return 0;
}