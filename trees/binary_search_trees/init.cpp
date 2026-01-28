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
class Pair{
    public:
        BTNode* head = nullptr;
        BTNode* tail = nullptr;

        Pair(): head(nullptr), tail(nullptr){}
};

class BSTNode{
    BTNode* root;
    private:
        void printTree(BTNode* node){
            if(!node) {
              return;
            }
            cout << node -> data <<": ";
            if(node -> left) {
             cout << "L" << node -> left -> data;
            }
            if(node -> right) {
             cout << "R" << node -> right -> data;
            }
            cout << endl;
            printTree(node -> left);
            printTree(node -> right);
        }
        bool hasData(BTNode* node, int el){
             if(!node){
                return false; 
            }
            if (el == node -> data) {
                return true;
            } else if (el > node -> data) {
                return hasData(node -> right, el);
            } else {
                return hasData(node -> left, el);
            }
        }
        BTNode* insertData(BTNode* node, int el){
            if(!node){
                node = new BTNode(el);
                return node;
            }
            if(node -> data > el){
               node -> left = insertData(node -> left, el);
            }else{
               node -> right = insertData(node -> right, el);
            }
            return node;
        }
        BTNode* deleteData(BTNode* node, int el){
            if(!node) return nullptr;
            if(node -> data == el){
                BTNode* temp = node;
                if(node -> right && node -> left){
                    temp = temp -> left;
                    while(temp -> right){
                        temp = temp -> right;
                    }
                    node -> data = temp -> data;
                    node -> left = deleteData(node -> left, temp -> data);
                }else if(node -> left){
                    node = temp -> left;
                    temp -> left = nullptr;
                    delete temp;
                }else if(node -> right){
                    node = temp -> right;
                    temp -> right = nullptr;
                    delete temp;
                }else{
                    delete node;
                    return nullptr;
                }
            }else if(node -> data < el){
                node -> right = deleteData(node -> right, el);
            }else{
                node -> left = deleteData(node -> left, el);
            }
            return node;
        }
        Pair flattenBST(BTNode* node){
            if (!node){
                Pair p;
                p.head = nullptr;
                p.tail = nullptr;
                return p;
            }else if (!node -> left && !node -> right){
                Pair p;
                p.head = node;
                p.tail = node;
                return p; 
            }else if (node -> left && !node -> right){
                Pair left_ll = flattenBST(node -> left);
                Pair ans;
                left_ll.tail -> right = node;
                node -> left = left_ll.tail;
                node -> right = nullptr;
                ans.head = left_ll.head;
                ans.tail = node;
                return ans;
            }else if (!node -> left && node -> right){
                Pair right_ll = flattenBST(node -> right);
                Pair ans;
                node -> right = right_ll.head;
                right_ll.head -> left = node;
                right_ll.tail -> right = nullptr;
                ans.head = node;
                ans.tail = right_ll.tail;
                return ans;
            }else {
                Pair left_ll = flattenBST(node -> left);
                Pair right_ll = flattenBST(node -> right);
                left_ll.tail -> right = node;
                node -> left = left_ll.tail;
                node -> right = right_ll.head;
                right_ll.head -> left = node;
                right_ll.tail -> right = nullptr;
                Pair ans;
                ans.head = left_ll.head;
                ans.tail = right_ll.tail;
                return ans;
            }
        }

    public:
        BSTNode(){
            root = nullptr;
        }
        BSTNode(int el){
            root = new BTNode(el);
        }
        ~BSTNode(){
            delete root;
        }
        void printTree(){
            printTree(root);
        }
        bool hasData(int el){
            return hasData(root, el);
        } 
        void insertData(int el){
            root = insertData(root, el);
        }
        void deleteData(int el){
            root = deleteData(root, el);
        }
        void flattenBST(){
           Pair p;
           p = flattenBST(root);
           root = p.head;
        }
        void clear(){
            root = nullptr;
        }
        BTNode* getRoot(){
            return root;
        }
};

void printList(BTNode* head){
    while(head){
        cout << head->data << " ";
        head = head->right;
    }
}
void destroyList(BTNode* node){
    while(node){
        BTNode* next = node->right;
        node->left = node->right = nullptr;
        delete node;
        node = next;
    }
}
int main(){
    BSTNode b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(3);
    b.insertData(7);
    b.insertData(20);
    b.insertData(15);
    b.printTree();
    cout << endl << endl;
    b.flattenBST();
    printList(b.getRoot());
    destroyList(b.getRoot());
    b.clear();
    return 0;
}