//CPP 
#include <bits/stdc++.h> 
using namespace std;

bool check(string date){
    //format YYYY-MM-DD
    //check length
    if(date.size() > 10) return false;
    //check "-"
    if(date[4] != '-' || date[7] != '-') return false;
    //check MM
    int month = (date[5] - '0')*10 + (date[6] - '0');
    if(month > 12 || month <= 00) return false;
    //check DD
    int day = (date[8] - '0')*10 + (date[9] - '0');
    if(day > 30 || day <= 00) return false;
    
    cout<< date.substr(0, 4) << ' ' << month << ' ' <<day;
    return true;
}

int main() 
{ 
    string date; getline(cin, date);
    if(!check(date)) cout<< "INCORRECT";
    return 0;
}
