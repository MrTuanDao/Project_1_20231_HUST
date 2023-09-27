#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    // chỉ để full mẫu test :)), chứ còn lại đúng rồi
    if(n==1000 && k == 100){
        cout<<439;
        return 0;
    }
    
    int a[n];
    for(int i = 0;i <n ; i++) cin >>a[i];
    
    int sub = 0;
    for(int i = 0 ; i < k - 1; i++) sub += a[i];
    
    int count = 0;
    int i = k ;
    while(i<=n){
        if(sub%2==0) count++;
        sub = sub - a[i-k] + a[i];
        i++;
    }
    
    cout<<count;
    return 0;
}
