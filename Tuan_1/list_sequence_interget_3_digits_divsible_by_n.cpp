//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n; cin>>n;
    
    for(int i = 1; n*i < 1000; i ++){
        if (n*i < 100) continue;
        cout << n*i << ' ';
    }
    return 0;
}
