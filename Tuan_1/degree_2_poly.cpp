#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c){
    cout<<fixed;
    cout<<setprecision(2);
    float delta = (b*b - 4*a*c);
    if(delta < 0){
        cout<<"NO SOLUTION";
    }
    else if(delta == 0){
        cout << float(-b/(2*a));
    }
    else{
        cout << (-b - sqrt(delta))/(2*a) << ' ' << (-b + sqrt(delta))/(2*a);
    }
}

int main(){
    int a, b, c; cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}
