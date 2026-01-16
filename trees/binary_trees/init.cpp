#include <iostream>

using namespace std;

class BTNode{
    public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int el): data(el), left(nullptr), right(nullptr){}

    void printTree(){
        cout << this -> data << " ";
        if(this -> left){
            this -> left -> printTree();
        }
        if(this -> right){
            this -> right -> printTree();
        }
    }

    ~BTNode(){
        delete(left);
        delete(right);
    }
};

BTNode* takeInput(){
    int root_data;
    cout << "Enter the value for the root" << endl;
    cin >> root_data;
    if(root_data == -1){
        return nullptr;
    }else{
        BTNode* root = new BTNode(root_data);
        root -> left = takeInput();
        root -> right = takeInput();
        return root;
    }
}
int diameterOfTree(BTNode* root){
    if(!root){
        return 0;
    }
    return 
}
// 0 1 2 3 4 5 6 7 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    BTNode* root = takeInput();
    root -> printTree();

    return 0;
}