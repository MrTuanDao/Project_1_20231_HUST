#include <bits/stdc++.h>
using namespace std;

bool check(string _time){
    // format: hh:mm:ss
    // check ':'
    if(_time[2] != ':' || _time[5] != ':') return false;
    // check hh
    int hh = (_time[0] - '0')*10 + (_time[1] - '0');
    if( 0 > hh || hh > 23 ) return false;
    //check mm
    int mm = (_time[3] - '0')*10 + (_time[4] - '0');
    if( mm < 0 || 59 < mm) return false;
    //check ss
    int ss = (_time[6] - '0')*10 + (_time[7] - '0');
    if ( ss < 0 || 59 < ss) return false;
    
    cout << hh*3600 + mm*60 + ss;
    return true;
    
}

int main(){
    string _time; cin >> _time;
    
    if(!check(_time)) cout<<"INCORRECT";
    return 0;
}
