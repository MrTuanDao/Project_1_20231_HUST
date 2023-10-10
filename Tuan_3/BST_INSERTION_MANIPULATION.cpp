#include <bits/stdc++.h>
using namespace std;

// cai dat BST bang Linked Node
typedef struct treeNode{
    int val;
    treeNode *left, *right;
}treeNode;

treeNode *head = new treeNode();

treeNode *makeTreeNode(int x){
    treeNode *p = new treeNode();
    p->val = x;
    return p;
}

void insert(int x, treeNode *node){ // insert k neu k chua ton tai// cai dat theo de quy
    // dieu kien dung
    if(x > node->val){
        if(node->right == NULL) node->right = makeTreeNode(x);
        else insert(x, node->right);
    }
    else if(x < node->val){
        if(node->left == NULL) node->left = makeTreeNode(x);
        else insert(x, node->left);
    }
}

void preOrderTraversal(treeNode *node){ // cai dat theo de quy
    // dieu kien dung
    if (node == NULL) return;
    cout << node->val << ' ';
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
    
}

int main(){
    string temp; int x; cin >> temp >> x; head->right = makeTreeNode(x);
    while(true){
        string query; cin >> query;
        if(query == "#") break;
        else if(query == "insert") {
            int k; cin >> k;
            insert(k, head->right);
        }
    }
    
    preOrderTraversal(head->right);
    return 0;
}
