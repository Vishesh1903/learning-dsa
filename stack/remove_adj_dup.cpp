#include <iostream>
#include <string>
#include <stack>

using namespace std;

void removeAdjDuplicates(string& s){
    stack<char> st;
    string result = "";
    for(auto it: s){
        if(st.empty()){
            st.push(it);
        }else if(st.top() == it){
            st.pop();
        }else{
            st.push(it);
        }
    }
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    s = result;
}
void removeAdjDuplicates2(string& s){
    stack<char> st;
    string result = "";
    for(int i = 0; i < s.length(); s++){ 
        if(st.empty()){
            st.push(s[i]);
        }else if(st.top() == s[i]){
            st.pop();
        }else{
            st.push(it);
        }
    }
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    s = result;
}

int main(){
    string s = "aabbcccd";
    removeAdjDuplicates(s);
    cout << s << endl;
    return 0;
}