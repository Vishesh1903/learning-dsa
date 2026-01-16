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

BTNode* constructTree(vector<int> postorder, vector<int> inorder, int post_order_start, int post_order_end , int inorder_start, int inorder_end){
    if(post_order_start > post_order_end || inorder_start > inorder_end){
        return nullptr;
    }
    BTNode* root = new BTNode(postorder[post_order_end]);
    int i = 0;
    while(inorder[i] != root -> data){
        i++;
    }
    int left_inorder_start = inorder_start;
    int left_inorder_end = i - 1;
    int right_inorder_start = i + 1;
    int right_inorder_end = inorder_end;

    int left_postorder_start = post_order_start;
    int left_postorder_end = left_inorder_end - left_inorder_start + left_postorder_start;
    int right_postorder_end = post_order_end - 1;
    int right_postorder_start = left_postorder_end + 1;
    root -> left = constructTree(postorder, inorder, left_postorder_start, left_postorder_end, left_inorder_start, left_inorder_end);
    root -> right = constructTree(postorder, inorder, right_postorder_start, right_postorder_end, right_inorder_start, right_inorder_end);
    return root;

}
int main(){
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };
    BTNode* root = constructTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    levelOrderTraversal(root);

    return 0;
}