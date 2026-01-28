#include <iostream>
#include<unordered_map>
#include <map>

using namespace std;

int main(){
    map<string, int> mp;

    mp["abc"] = 1;
    mp["abc1"] = 10;
    mp["ab2"] = 20;
    mp["abc4"] = 80;
    mp["ac"] = 4;
    mp["abc"] = 9;

    mp.erase("abc");// can pass the key
    // mp.erase(it); // can pass the iterator
    // mp.erase(it, it + 10); // can pass the iterator
    
    for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it -> first << " " << it -> second << endl;
    }

    //another way to check

    if(mp.find("acd") == mp.end()){
        cout << "acd is not present" << endl;
    }

    return 0;
}