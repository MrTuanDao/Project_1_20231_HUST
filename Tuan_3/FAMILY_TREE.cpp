// Dao Quoc Tuan 20210891

#include <bits/stdc++.h>
using namespace std;

typedef struct personNode{
    string name;
    int gen = 0;
    int des = 0;
    personNode* parent = NULL;
    vector<personNode*> childs;
} personNode;

set<personNode*> personList; // chứa tất cả các nhân khẩu xuất hiện, tra cứu cho nó dễ 

personNode* makePerson(string newname){
    personNode *temp = new personNode();
    temp->name = newname;
    return temp;
}

void addChild(string childName, string parentName){
    // tim ra nguoi dua vao ten
    personNode *personWantToBeChild = NULL, *personWantToBeParent = NULL;
    for(auto it = personList.begin(); it != personList.end(); it++) {
        personNode *person = *it;
        if (person->name == parentName) personWantToBeParent = person;
        else if (person->name == childName) personWantToBeChild = person;
    }
    if(personWantToBeChild == NULL) personWantToBeChild = makePerson(childName);
    if(personWantToBeParent == NULL) personWantToBeParent = makePerson(parentName);
    personList.insert(personWantToBeChild);
    personList.insert(personWantToBeParent);
    
    personWantToBeParent->childs.push_back(personWantToBeChild);
    personWantToBeChild->parent = personWantToBeParent;
    
    // update generation
    personWantToBeParent->gen = personWantToBeChild->gen + 1;
    int tempDes = personWantToBeParent->gen;
    personNode *parentTemp = personWantToBeParent->parent;
    while(parentTemp != NULL){
        // cout << parentTemp->name << ' ' << parentTemp->des << endl;
        parentTemp->gen = tempDes + 1;
        tempDes = parentTemp->des;
        parentTemp = parentTemp->parent;
    }
    
    // update descendants
    personWantToBeParent->des += personWantToBeChild->des + 1;
    tempDes = personWantToBeChild->des;
    parentTemp = personWantToBeParent->parent;
    while(parentTemp != NULL){
        // cout << parentTemp->name << ' ' << parentTemp->des << endl;
        parentTemp->des += tempDes + 1;
        parentTemp = parentTemp->parent;
    }
}

int main(){
    while(true){
        string  childName; cin >> childName;
        if(childName == "***") break;
        else{
            string parentName; cin >> parentName;
            addChild(childName, parentName);
        }
    }
    while(true){
        string query; cin >> query;
        if(query == "***") break;
        else if(query == "generation"){
            string personName; cin >> personName;
            for(auto it = personList.begin(); it != personList.end(); it++) {
                personNode *person = *it;
                if (person->name == personName) cout << person->gen << endl;
            }
        }
        else if (query == "descendants"){
            string personName; cin >> personName;
            for(auto it = personList.begin(); it != personList.end(); it++) {
                personNode *person = *it;
                if (person->name == personName) cout << person->des << endl;
            }
        }
    }
    return 0;
}
