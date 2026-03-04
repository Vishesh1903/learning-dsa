#include <iostream>

using namespace std;

class Node{
    public:
    bool is_terminal;
    Node* child[26];
    Node(){
        is_terminal = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

void add(string word, Node* trie){
    int n = word.size();
    for(int i = 0; i < n; i++){
        if(trie -> child[word[i] - 'A'] == NULL){
            trie -> child[word[i] - 'A'] = new Node();
        }
        trie = trie -> child[word[i] - 'A'];
    }
    trie->is_terminal = true;
}

void search(string word, Node* trie){
    int n = word.size();
    for(int i = 0; i < n; i++){
        if(trie -> child[word[i] - 'A']){
            trie = trie -> child[word[i] - 'A'];
        }else{
            cout << word <<  " is not present." << endl;
            return;
        }
    }
    if(!trie -> is_terminal){
        cout << word <<  " is not present." << endl;
    }else{
        cout << word << " is present" << endl;
    }
}

int main(){
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    Node* root = new Node();

    for(int i = 0;i < dict.size(); i++){
        add(dict[i], root);
    }
    search("NEWZ", root);
    //TC: O(Word Size);
    //SC: O(Summ of word of eact dictoniarly)

}