#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    int m = v.size();
    int n = v[0].size();
    int rs = 0, cs = 0, rend = m - 1, cend = n - 1, count = 0;

    vector<int> ans;

    while (cs <= cend && rs <= rend)
    {
        for (int i = cs; i <= cend; i++)
        {
            ans.push_back(v[rs][i]);
            count++;
        }
        rs++;
        if (count == m * n)
        {
            break;
        }
        for (int i = rs; i <= rend; i++)
        {
            ans.push_back(v[i][cend]);
            count++;
        }
        cend--;
        if (count == m * n)
        {
            break;
        }
        for (int i = cend; i >= cs; i--)
        {
            ans.push_back(v[rend][i]);
        }
        rend--;
        if (count == m * n)
        {
            break;
        }
        for (int i = rend; i >= rs; i--)
        {
            ans.push_back(v[i][cs]);
        }
        cs++;
        if (count == m * n)
        {
            break;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }


    return 0;
}