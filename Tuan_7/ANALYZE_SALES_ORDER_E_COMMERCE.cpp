#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int total_number_orders = 0, total_revenue = 0;
map <string, int> revenue_of_shop;
map < string, map<string, int>> total_consume_of_customer_shop;
map <int, int> total_revenue_in_period;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int id = 1;
    string cutomerID, productID, shopID, time_point; int price;
    while (true) {
        cin >> cutomerID; if (cutomerID == "#") break;
        cin >> productID >> price >> shopID >> time_point;
        
        total_number_orders++;
        total_revenue += price;
        revenue_of_shop[shopID] += price;
        total_consume_of_customer_shop[shopID][cutomerID] += price;
        
        // convert time_point to seconds
        int time_ = (time_point[7] - '0') + (time_point[6] - '0')*10 
                    + (time_point[4] - '0')*60 + (time_point[3] - '0')*600
                    + (time_point[1] - '0')*3600 + (time_point[0] - '0')*36000;
        total_revenue_in_period[time_] += price;
    }
    
    // Prefix sum
    auto it = total_revenue_in_period.begin();
    int pre = total_revenue_in_period.begin()->second;
    for (it++; it != total_revenue_in_period.end(); it++) {
        pre = it->second += pre;
    }
    total_revenue_in_period[0] = 0;
    total_revenue_in_period[MAX] = MAX;
    
    string query;
    while (true) {
        cin >> query; 
        if (query == "#") break;
        else if (query == "?total_number_orders") cout << total_number_orders << '\n';
        else if (query == "?total_revenue") cout << total_revenue << '\n';
        else if (query == "?revenue_of_shop") {
            cin >> shopID; cout << revenue_of_shop[shopID] << '\n';
        } else if (query == "?total_consume_of_customer_shop") {
            cin >> cutomerID >> shopID; cout << total_consume_of_customer_shop[shopID][cutomerID] << '\n';
        } else if (query == "?total_revenue_in_period") {
            
            string from_time, to_time; cin >> from_time >> to_time;
            int lowtime = (from_time[7] - '0') + (from_time[6] - '0')*10 
                        + (from_time[4] - '0')*60 + (from_time[3] - '0')*600
                        + (from_time[1] - '0')*3600 + (from_time[0] - '0')*36000;
            int uptime = (to_time[7] - '0') + (to_time[6] - '0')*10 
                        + (to_time[4] - '0')*60 + (to_time[3] - '0')*600
                        + (to_time[1] - '0')*3600 + (to_time[0] - '0')*36000;  
            
            auto itlow = total_revenue_in_period.lower_bound(lowtime); itlow--;
            auto itup = total_revenue_in_period.upper_bound(uptime); itup--;
            
            int low = itlow->second;
            int up = itup->second;
            
            cout << up - low << '\n'; 
            
        }
    }
    
    
    // for(auto it = total_revenue_in_period.begin(); it != total_revenue_in_period.end(); it++)
    //     if (it->first > 75000) cout << it->first << ' ' << it->second << endl;
    
    return 0;
}
