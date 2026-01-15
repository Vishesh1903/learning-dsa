#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
    public:
        int data;
        vector<TreeNode*> children;
        TreeNode(int value): data(value) {}

        void printTreeLevelWise(){
            queue<TreeNode*> q;
            q.push(this);
            while(!q.empty()){
                TreeNode* front = q.front();
                q.pop();
                cout << front -> data << ": ";
                for(int i = 0; i < front -> children.size(); i++){
                    cout << front -> children[i] -> data << " ";
                    q.push(front -> children[i]);
                }
                cout << endl;
            }
        }

};

TreeNode* takeInputLevelWise(){
    queue<TreeNode*> q;
    int root_value;
    cout << "Enter the value of the root node" << endl;
    cin >> root_value;

    TreeNode* root = new TreeNode(root_value);
    q.push(root);
    while(!q.empty()){
        int root_children;
        TreeNode* front = q.front();
        q.pop();
        cout << "Enter the number of children nodes for :- " << front -> data << endl;
        cin >> root_children;
        for(int i = 0; i < root_children; i++){
           int value;
           cout << "Enter the value for "<< i + 1 << "th child node of "<< front -> data << endl;
           cin >> value;
           TreeNode* leaf = new TreeNode(value);
           front -> children.push_back(leaf);
           q.push(leaf);
        }
    }
    return root;
}

int countNodes(TreeNode* root){
    int ans = 1;
    for(int i = 0; i < root -> children.size(); i++){
        ans += countNodes(root -> children[i]);
    }
    return ans;
}

// Below is the input to create the tree on a go
// 0 3 1 2 3 2 4 5 1 6 0 0 0 1 7 1 8 0
int main(){
    TreeNode* root = takeInputLevelWise();
    root->printTreeLevelWise();
    cout << endl;
    int nodes = countNodes(root);
    cout << "No of Nodes:- " << nodes << endl;
    return 0;
}