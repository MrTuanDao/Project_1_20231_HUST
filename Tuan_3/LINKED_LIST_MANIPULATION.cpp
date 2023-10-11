#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
} Node;
Node* head = new Node();

Node *makenode(int x){
    Node *p = new Node();
    p->val = x;
    return p;
}

Node *addressOf(int x){
    Node *cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
        if (cur->val == x) return cur;
    }
    return cur->next;
}

void addfirst(int x){
    if(addressOf(x) != NULL) return;
    Node* cur = makenode(x);
    cur->next = head->next;
    head->next = cur;
}

void addlast(int x){
    Node* cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
        if (cur->val == x) return;
    }
    cur->next = makenode(x);
}

void addafter(int u, int v){// them phan tu u vao sau phan tu v, neu v da ton tai va u chua ton tai
    Node *p = addressOf(v);
    if(p != NULL && addressOf(u) == NULL) {
        Node *p1 = makenode(u);
        p1->next = p->next;
        p->next = p1;
    }
    return;
}

void addbefore(int u, int v){
    if(addressOf(u) != NULL) return;
    Node *prev = head, *cur = head->next;
    while(cur->next != NULL && cur->val != v){
        prev = cur;
        cur = cur->next;
    }
    if(cur->val == v){
        Node *temp = makenode(u);
        prev->next = temp;
        temp->next = cur;
    }
}

void remove_node(int k){
    Node *prev = head, *cur = head->next;
    while(cur->next != NULL && cur->val != k){
        prev = cur;
        cur = cur->next;
    }
    // cout << cur->val << endl;
    if(cur->val == k) prev->next = cur->next;
}

void printList(){
    Node *cur = head->next;
    while(cur != NULL){
        cout << cur->val << ' ';
        cur = cur->next;
    }
}

void reverse(){
    Node *prev = NULL, *cur = head->next; if(cur == NULL) return;
    Node *aft = cur->next;
    while(aft != NULL){
        cur->next = prev;
        prev = cur;
        cur = aft;
        aft = aft->next;
    }
    cur->next = prev;
    head->next = cur;
}

int main()
{
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        addlast(x);
    }
    
    while(true){
        string query; cin >> query; 
        if(query == "#") break;
        else if(query == "addlast") {
            int x; cin >> x; addlast(x);
        }
        else if(query == "addfirst"){
            int x; cin >> x; addfirst(x);
        }
        else if(query == "addafter"){
            int u, v; cin >> u >> v; addafter(u, v);
        }
        else if(query == "addbefore"){
            int u, v; cin >> u >> v; addbefore(u, v);
        }
        else if(query == "remove"){
            int x; cin >> x; remove_node(x);
        }
        else if(query == "reverse") reverse();
    }
    
    printList();
    return 0;
}
