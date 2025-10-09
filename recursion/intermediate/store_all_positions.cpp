#include <iostream>

using namespace std;

int storeAllPositions(int arr[], int n, int key, int index, int ans[], int j)
{
    if (index == n)
    {
        return 0;
    }
    if (arr[index] == key)
    {
        ans[j] = index;
        return 1 + storeAllPositions(arr, n, key, index + 1, ans, j + 1);
    }
    else
    {
        return storeAllPositions(arr, n, key, index + 1, ans, j);
    }
}
void storeAllPositionsV2(int arr[], int n, int key, int index, vector<int>& ans)
{
    if (index < 0)
    {
        return;
    }
    if (arr[index] == key)
    {
        storeAllPositionsV2(arr, n, key, index - 1, ans);
        ans.push_back(index);
    }
    else
    {
        storeAllPositionsV2(arr, n, key, index - 1, ans);
    }
}
int main()
{
    int arr[] = {1, 2, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;
    int ans[5];
    int elements = storeAllPositions(arr, size, key, 0, ans, 0);

    for (int i = 0; i < elements; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    vector<int> ans_v2;
    storeAllPositionsV2(arr, size, key, size - 1, ans_v2);
    for (int i = 0; i < ans_v2.size(); i++)
    {
        cout << ans_v2[i] << " ";
    }
        return 0;
}