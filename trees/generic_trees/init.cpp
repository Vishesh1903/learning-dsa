#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
    public:
        int data;
        vector<TreeNode*> children;
        TreeNode(int value): data(value) {}

        void printTree(){
            cout << this -> data << ": ";
            for(int i = 0; i < children.size(); i++){
                cout << children[i] -> data << " ";
            }
            cout << endl;
            for(int i = 0; i < children.size(); i++){
                children[i] -> printTree();
            }
            return;
        }
};

TreeNode* takeInput(){
    int root_value;
    cout << "Enter the value of the root node" << endl;
    cin >> root_value;

    TreeNode* root = new TreeNode(root_value);
    TreeNode* temp = root;
    int root_children;
    cout << "Enter the number of children nodes :- " << endl;
    cin >> root_children;
    if(root_children <=0){
        return root;
    }else{
        for(int i = 0; i < root_children; i++){
           temp -> children.push_back(takeInput());
        }
    }
    return root;    
}

int main(){
    TreeNode* root = takeInput();
    root->printTree();
    cout << endl;
    return 0;
}