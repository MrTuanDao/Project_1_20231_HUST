//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{   int n; cin >> n; n = n - 2;
    int left = 0, right = 1;
    while(n--){
        int tmp = right;
        right = left + right;
        left = tmp;
    }
    cout << right;
}
