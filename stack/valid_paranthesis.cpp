#include <iostream>

using namespace std;

bool isValid(string s) {
  stack<char> st;
  for(char c : s){
    if(c == '[' || c == '(' || c == '{'){
      st.push(c);
    }else{
      if(st.empty()){
        return false;
      }
      if((st.top() == '[' && c == ']') || (st.top() == '(' && c == ')') || (st.top() == '{' && c  == '}') ){
        st.pop();
      }else{
        return false;
      }
    }
  }
  if(st.empty()){
    return true;
  }else{
    return false;
  }
}

int main() {

  string s = "([])";
  bool result = isValid(s);
  cout << result << endl;
  return 0;
}