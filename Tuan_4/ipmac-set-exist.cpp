#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n; set<int> check;
int res[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(check.find(x) != check.end()) res[i] = 1;
        check.insert(x);
    }
    
    for(int i = 1; i <= n; i++) cout << res[i] << endl;
    
    return 0;
}
