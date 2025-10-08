#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &v, int key)
{
    for (int i = 0; i < v.size(); i++){
        if (v[i] == key){
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 4, 5, 7};

    int key;
    cout << "Enter the key you want to search :" << endl;
    cin >> key;

    int index = linearSearch(v, key); // O(n) - n steps to traverse the array in worst case
    if (index == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }
    return 0;
}