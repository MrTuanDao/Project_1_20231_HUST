//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n; cin >> n;
    long int sum = 0;
    while(n--){
        int x; cin >> x;
        sum += x;
    }
    cout << sum;
}
