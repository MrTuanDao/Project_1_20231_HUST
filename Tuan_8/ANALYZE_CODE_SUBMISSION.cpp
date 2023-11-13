#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int total_number_submissions = 0, number_error_submision = 0;
map<string, int> number_error_submision_of_user;
map<string, int> total_point_of_user;
map<string, map<string, int>> total_point_of_user_per_problem;
map<int, int> number_submission_period;

void input() {
    string userid, problemid, time_point, status; int point;
    while (true) {
        cin >> userid; if (userid == "#") break;
        cin >> problemid >> time_point >> status >> point;
        
        ++total_number_submissions;
        if (status == "ERR") {
            ++number_error_submision;
            ++number_error_submision_of_user[userid];
        }
        if(total_point_of_user_per_problem[userid][problemid] < point) {
            total_point_of_user[userid] += point - total_point_of_user_per_problem[userid][problemid];
            total_point_of_user_per_problem[userid][problemid] = point;
        }
        
        // convert time_point to seconds
        int time_ = (time_point[7] - '0') + (time_point[6] - '0')*10 
                    + (time_point[4] - '0')*60 + (time_point[3] - '0')*600
                    + (time_point[1] - '0')*3600 + (time_point[0] - '0')*36000;
        ++number_submission_period[time_];
        // cout << userid << ' ' << problemid << ' ' << total_point_of_user_per_problem[userid][problemid] << endl;
    }
    
    // prefix sum
    number_submission_period[-1] = 0;
    number_submission_period[MAX] = 0;
    int pre = 0;
    for(auto &period: number_submission_period) { 
        pre = period.second += pre;
    }
    
    // for(auto &period: number_submission_period) {
    //     cout << period.first << ' ' << period.second << endl;
    // }
}

void solve() {
    string query;
    while (true) {
        cin >> query; 
        if (query == "#") break;
        else if (query == "?total_number_submissions") cout << total_number_submissions << '\n';
        else if (query == "?number_error_submision") cout << number_error_submision << '\n';
        else if (query == "?number_error_submision_of_user") {
            string userid; cin >> userid;
            cout << number_error_submision_of_user[userid] << '\n';
        } else if (query == "?total_point_of_user") {
            string userid; cin >> userid;
            cout << total_point_of_user[userid] << '\n';
        } else if (query == "?number_submission_period") {
            string from_time, to_time; cin >> from_time >> to_time;
            int lowtime = (from_time[7] - '0') + (from_time[6] - '0')*10 
                        + (from_time[4] - '0')*60 + (from_time[3] - '0')*600
                        + (from_time[1] - '0')*3600 + (from_time[0] - '0')*36000;
            int uptime = (to_time[7] - '0') + (to_time[6] - '0')*10 
                        + (to_time[4] - '0')*60 + (to_time[3] - '0')*600
                        + (to_time[1] - '0')*3600 + (to_time[0] - '0')*36000;  
            
            auto itlow = number_submission_period.lower_bound(lowtime); itlow--;
            auto itup = number_submission_period.upper_bound(uptime); itup--;
            
            int low = itlow->second;
            int up = itup->second;
            
            cout << up - low << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    
    return 0;
}
