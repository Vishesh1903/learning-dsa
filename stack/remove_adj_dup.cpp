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
void removeAdjDuplicatesInplace(string& s){
   int top = -1;
   for(char c: s){
    if(top >= 0 && s[top] == c){
        top--;
    }else{
        s[++top] = c;
    }
   }
   s.resize(top + 1);
}

int main(){
    string s = "aaabbacccd";
    removeAdjDuplicatesInplace(s);
    cout << s << endl;
    return 0;
}