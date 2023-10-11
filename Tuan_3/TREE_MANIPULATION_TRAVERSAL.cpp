#include <bits/stdc++.h>
using namespace std;

set<int> setId;

typedef struct node{
    int val;
    vector<node*> childs;
} node;

node *head = new node();

node* makeNode(int x){
    node *temp = new node();
    temp->val = x;
    return temp;
}

void makeRoot(int x){
    head = makeNode(x);
    setId.insert(x);
}

void insert(int u, int v){ // chen nut u vao cuoi danh sach nut con cua v, neu v da ton tai va u chua ton tai
    if(setId.count(u) != 0 || setId.count(v) == 0) return;
    setId.insert(u);
    queue<node*> q; q.push(head);
    node* addressOfv;
    while(!q.empty()){
        node *temp = q.front(); q.pop();
        if (temp->val == v) {
            addressOfv = temp; break;
        }
        for(auto it = temp->childs.begin(); it != temp->childs.end(); it++){
            node* child = *it;
            if(child != NULL) q.push(child);
        }
    }
    addressOfv->childs.push_back(makeNode(u));
}

void inOrder(node *nut_cay){ // cai dat bang recursive
    if(nut_cay->childs.empty()) {
        cout << nut_cay->val << ' '; return;
    }
    inOrder(nut_cay->childs[0]);
    cout << nut_cay->val << ' ';
    for(auto it = nut_cay->childs.begin() + 1; it != nut_cay->childs.end(); it++){
            node* child = *it;
            inOrder(child);
        }
}

void preOrder(node *nut_cay){
    if(nut_cay->childs.empty()) {
        cout << nut_cay->val << ' '; return;
    }
    cout << nut_cay->val << ' ';
    preOrder(nut_cay->childs[0]);
    for(auto it = nut_cay->childs.begin() + 1; it != nut_cay->childs.end(); it++){
            node* child = *it;
            preOrder(child);
        }
}

void postOrder(node *nut_cay){
    if(nut_cay->childs.empty()) {
        cout << nut_cay->val << ' '; return;
    }
    postOrder(nut_cay->childs[0]);
    for(auto it = nut_cay->childs.begin() + 1; it != nut_cay->childs.end(); it++){
            node* child = *it;
            postOrder(child);
        }
    cout << nut_cay->val << ' ';
}

int main(){
    while(true){
        string query; cin >> query;
        if(query == "*") break;
        else if (query == "MakeRoot"){
            int x; cin >> x;
            makeRoot(x);
        }
        else if (query == "Insert"){
            int u, v; cin >> u >> v;
            insert(u, v);
        }
        else if (query == "InOrder") {
            inOrder(head);
            cout << endl;
        }
        else if (query == "PreOrder"){
            preOrder(head);
            cout << endl;
        }
        else if (query == "PostOrder"){
            postOrder(head);
            cout<<endl;
        }
    }
    return 0;
}
