#include <iostream>
#include <string>
#include <map>

using namespace std;

//Brute Force
string printLongestCommonSubsequence(string a, string b){
    int temp = -1;
    string output = ""; 
    for(int i = 0; i < a.size(); i++){
        for(int j = temp + 1; j < b.size(); j++){
            if(a[i] == b[j] && j > temp){
                output += b[j];
                temp = j;
                break;
            }
        }
    }
    return output;
}

//Recursion
int longestCommonSubsequence(string a, string b, int i = 0, int j = 0){
    if(i == a.length() || j == b.length()){
        return 0;
    }
    if(a[i] == b[j]){
        return 1 + longestCommonSubsequence(a, b, i + 1, j + 1);
    }else {
        return max(longestCommonSubsequence(a, b, i + 1, j), longestCommonSubsequence(a, b, i, j + 1));
    }
}

//Recursion
// LCS using Memoization or DP (Bottom Up Approach)
int longestCommonSubsequence(string a, string b, vector<vector<int>> dp, int i = 0, int j = 0){
    if(i == a.size() || j == b.size()){
        return 0;
    }
    int &ans = dp[i][j];
    if(ans != -1){
        return ans;
    }
    if(a[i] == b[j]){
        ans = 1 + longestCommonSubsequence(a, b, i + 1, j + 1);
        return ans;
    }else{
        ans = max(longestCommonSubsequence(a, b, i + 1, j), longestCommonSubsequence(a, b, i, j + 1));
        return ans;
    }
}

// LCS using Top Down Approach
int longestCommonSubsequence(string a, string b){
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string a = "mapengo";
    string b = "palppe";

    int i = 0;
    cout << a.size() << endl;
    a[a.size() - 1] = "";
    cout << a.size() << endl;
    // cout << longestCommonSubsequence(a, b) << endl;

    return 0;
}