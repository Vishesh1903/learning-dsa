#include <iostream>

using namespace std;

class BTNode{
    public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int el): data(el), left(nullptr), right(nullptr){}

    ~BTNode(){
        delete(left);
        delete(right);
    }
};
void levelOrderTraversal(BTNode* root){
    if(!root){
        return;
    }
    queue<BTNode*> q;
    q.push(root);
    while(!q.empty()){
        BTNode* front = q.front();
        q.pop();
        cout << front -> data << " ";
        if(front -> left){
            q.push(front -> left);
        }
        if(front -> right){
            q.push(front -> right);
        }
    }
}

BTNode* takeInputLevelWise(){
    int root_data;
    cout << "Enter the value for the root" << endl;
    cin >> root_data;
    if(root_data == -1){
        return nullptr;
    }
    queue<BTNode*> q;
    BTNode* root = new BTNode(root_data);
    q.push(root);
    while(!q.empty()){
        BTNode* front = q.front();
        q.pop();
        cout << "Enter the value for left node of " << front -> data << endl;
        int left_data;
        cin >> left_data;
        if(left_data == -1){
            front -> left = nullptr; 
        }else{
            front -> left = new BTNode(left_data);
            q.push(front -> left);
        }
        cout << "Enter the value for right node of " << front -> data << endl;
        int right_data;
        cin >> right_data;
        if(right_data == -1){
            front -> right = nullptr; 
        }else{
            front -> right = new BTNode(right_data);
            q.push(front -> right);
        }
    }
    return root;
}

void minValue(BTNode* root, int& min_val){
    if(!root){
        return;
    }
    min_val = min(min_val, root -> data);
    minValue(root -> left, min_val);
    minValue(root -> right, min_val);
}
void maxValue(BTNode* root, int& max_val){
    if(!root){
        return;
    }
    max_val = max(max_val, root -> data);
    maxValue(root -> left, max_val);
    maxValue(root -> right, max_val);
}

// 0 1 2 3 4 5 6 7 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    BTNode* root = takeInputLevelWise();
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;
    int min = INT_MAX;
    int max = INT_MIN;
    minValue(root, min);
    maxValue(root, max);
    cout << "The smallest key present in the tree is:- " << min << endl;
    cout << "The largest key present in the tree is:- " << max << endl;
    return 0;
}