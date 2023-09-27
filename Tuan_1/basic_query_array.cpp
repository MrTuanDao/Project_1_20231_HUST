// do n nhỏ hơn 1000 nên truy vấn max trong khoảng i và j theo kiểu này vẫn được
// nếu n lên tới 1e6 thì sẽ cần tạo sparse table
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+5];
    int _max = -1000, _min = 1000;
    int sum = 0;
    
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        _min = min(_min, a[i]);
        _max = max(_max, a[i]);
        sum += a[i];
        
    }
    
    while(cin){
        string query; cin >> query;
        if(query.compare("find-max") == 0) cout<<_max<<endl;
        if(query.compare("find-min") == 0) cout<<_min<<endl;
        if(query.compare("sum") == 0) cout << sum << endl;
        if(query.compare("find-max-segment") == 0){
            int left, right; cin >>left >> right;
            int max_seg = a[left-1];
            while(left++ <= right - 1){
                max_seg = max(max_seg, a[left-1]);
            }
            cout<<max_seg<<endl;
        }
    }
    
    
}
