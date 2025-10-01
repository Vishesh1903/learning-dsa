#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s = "abc";
    string *sp = new string;
    *sp = "nnonsodfn";

    vector<string> str = {"abc", "def", "wertyuio"};

    for (int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
        sort(str[i].begin(), str[i].end());
        cout << str[i] << endl;
    }

    string s4 = s + *sp;
    cout << s4 << endl;
    string s5 = s.substr(1, 2);
    cout << s5 << endl;

    int a = 123145;
    string s6 = to_string(a);
    cout << s6 << endl;


    return 0;
}