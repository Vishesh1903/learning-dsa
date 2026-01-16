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

BTNode* constructTree(vector<int> preorder, vector<int> inorder, int pre_order_start, int pre_order_end , int inorder_start, int inorder_end){
    if(pre_order_start > pre_order_end || inorder_start > inorder_end){
        return nullptr;
    }
    BTNode* root = new BTNode(preorder[pre_order_start]);
    int i = 0;
    while(inorder[i] != root -> data){
        i++;
    }
    int left_inorder_start = inorder_start;
    int left_inorder_end = i - 1;
    int right_inorder_start = i + 1;
    int right_inorder_end = inorder_end;
    int left_preorder_start = pre_order_start + 1;
    int left_preorder_end = left_inorder_end - left_inorder_start + left_preorder_start;
    int right_preorder_start = left_preorder_end + 1;
    int right_preorder_end = inorder_end;
    root -> left = constructTree(preorder, inorder, left_preorder_start, left_preorder_end, left_inorder_start, left_inorder_end);
    root -> right = constructTree(preorder, inorder, right_preorder_start, right_preorder_end, right_inorder_start, right_inorder_end);
    return root;
}
int main(){
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    BTNode* root = constructTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    levelOrderTraversal(root);

    return 0;
}