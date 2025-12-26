#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printAllSubsequences(char ch[], vector<char> output, int i = 0){
    if(ch[0] == '\0'){
        for (char c : output) cout << c;
        cout << endl;
        return;
    }
    output.push_back(ch[0]);
    printAllSubsequences(ch + 1, output, i + 1);
    output.pop_back();
    printAllSubsequences(ch + 1, output, i);
}
void storeAllSubsequences(char ch[], vector<char> output, int i, vector<vector<char>>& ans){
    if(ch[0] == '\0'){
        ans.push_back(output);
        return;
    }
    output.push_back(ch[0]);
    storeAllSubsequences(ch + 1, output, i + 1, ans);
    output.pop_back();
    storeAllSubsequences(ch + 1, output, i, ans);
}

int main(){
    char input[] = "abc";
    vector<char> output;
    vector<vector<char>> ans;
    printAllSubsequences(input, output, 0);
    storeAllSubsequences(input, output, 0, ans);
    for(int i = 0; i < ans.size(); i++){
        for (char c : ans[i]){ 
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}