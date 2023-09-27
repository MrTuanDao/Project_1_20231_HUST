//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string string1;
    while(cin){
        getline(cin, string1);
        for(auto it = string1.begin(); it != string1.end(); it++){ //auto là tự gán kiểu dữ liệu
            char c = *it;
            if ( c >= 97 && c <= 123) c = c - 32;
            cout << c;
        }
        cout<<endl;
    }
    return 0;
}
