//C++ 
#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 20, MAXM = 30;
int n, m;
int cur_sum = 0;
int res[MAXN];

void ghiNhan(){
    for(int i = 1; i <= n; i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}

void Try(int k){
    if (k == n){
        res[n] = m - cur_sum;
        ghiNhan();
        return;
    }
    for(int i = 1; i <= (m - (n - 1)) ; i++){
        res[k] = i;
        cur_sum += i;
        
        if (cur_sum <m && k < n) Try(k + 1);
      
        cur_sum -= i;
    }    
}

int main() 
{ 
    cin >> n >> m;
    Try(1);
    return 0;
}
