// đầu bài nên ghi rõ ràng, xâu 1 không chứa dấu cách, 
// nếu xâu 1 chứa dấu cách thì việc xử lý xâu T sẽ trở nên khá khó khăn

#include<bits/stdc++.h>
using namespace std;

int main(){
    string p1, p2;
    getline(cin, p1);
    getline(cin, p2);
    while(cin){
        string temp; cin >> temp;
        if(temp.compare(p1) == 0) temp = p2;
        cout<<temp<<' ';
    }
    return 0;
}
