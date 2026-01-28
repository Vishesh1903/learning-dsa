#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    unordered_map<string, int> map;
    pair<string, int> p("abc", 1);
    map.insert(p);

    cout << map["abc"] << endl; // square brackets to assign and access

    cout << map.at("abc") << endl; // at function for accessing the key

    if(map.count("ghi") > 0){
        cout << "ghi key is present" << endl;
    }else{
        cout << "key is absent" << endl;
    }

    for(auto s: map){
        cout << s.first << endl;
        cout << s.second << endl;
    }

    cout << map.size() << endl; // how many key value pairs are present

    return 0;
}