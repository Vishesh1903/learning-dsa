#include <iostream>
#include <stack>
#include <string>
using namespace std;

// below is the example of postfix expression
// const string = ['4', '13', '5', '/', '+']
// (4 + (13 / 5)) 
int evaluatePostfix(vector<string> c) {
  stack<int> operands;
  for(int i = 0; i < c.size(); i++){
    if(c[i] != "+" && c[i] != "/" && c[i] != "-" && c[i] != "*"){
      operands.push(stoi(c[i]));
    } else {
      if(operands.size() < 2){
        return -1;
      }
      int r_value = operands.top();
      if(r_value == 0 && c[i] == "/"){
        return -1;
      }
      operands.pop();
      int l_value = operands.top();
      operands.pop();
      int result = 0;
      if(c[i] == "+"){
        result = l_value + r_value;
      } else if(c[i] == "-"){
        result = l_value - r_value;
      } else if (c[i] == "*") {
        result = l_value * r_value;
      } else if (c[i] == "/") {
        result = l_value / r_value;
      }
      operands.push(result);
    }
  }
  if(operands.size() != 1){
    return -1;
  }
  return operands.top();
}

int main() {
  vector<string> s = {"4", "13", "5", "/", "+"};
  int result = evaluatePostfix(s);
  if(result == -1){
    cout << "Invalid expression" << endl;
  } else {
    cout << result << endl;
  }
  return 0;
}