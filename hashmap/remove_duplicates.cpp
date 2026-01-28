#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> ans = {1,2,2,4,5,6,1,5,8,9,3,3};

    unordered_map<int, int> map;

    for(int i = 0; i < ans.size(); i++){
        map[ans[i]]++;
    }
    vector<int> result;
    for(auto s: map){
        result.push_back(s.first);
    }
    for(const int s: result){
        cout << s << " ";
    }

    return 0;
}