#include<bits/stdc++.h>
using namespace std;

set<string> mySet;

int main(){
    while(true){
        string book; cin >> book;
        if(book == "*") break;
        else mySet.insert(book);
    }
    // for(auto it = mySet.begin(); it != mySet.end(); it++){
        // cout << *it << endl;
    // }
    
    while(true){
        string query; cin >> query;
        if(query == "***") break;
        else if(query == "find"){
            string book; cin >> book;
            if(mySet.find(book) != mySet.end()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (query == "insert") {
            string book; cin >> book;
            if(mySet.find(book) != mySet.end()) cout << 0 << endl;
            else cout << 1 << endl;     
            mySet.insert(book);
        }
    }
    return 0;
}
