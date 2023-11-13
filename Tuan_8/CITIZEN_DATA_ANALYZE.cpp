// hoàn thiện 90%, còn max indepent set sẽ được học, quay lại làm sau, giờ còn có cái khác để làm

#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
int number_people;
map<string, int> number_people_born_at;
int generation[N];
map<string, int> number_people_born_between;
int MAX_UNRELATED_PEOPLE = -1;

void input() {
    memset(generation, 0, sizeof(generation));
    string query;
    int code, father_code, mother_code, region_code; string date_of_birth, is_alive;
    while (true) {
        cin >> query; if (query == "*") break; code = stol(query);
        cin >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;
        
        ++number_people;
        ++number_people_born_at[date_of_birth];
        if (father_code != 0) generation[code] = max(generation[father_code], generation[mother_code]) + 1;
        ++number_people_born_between[date_of_birth];
    }
    
    // prefix sum
    number_people_born_between[""] = 0;
    number_people_born_between["9999-99-99"] = 0;
    int pre = 0;
    for (auto &date: number_people_born_between) {
        pre = date.second += pre;
    }
}

int max_independent_set() {
    if (MAX_UNRELATED_PEOPLE != -1) return MAX_UNRELATED_PEOPLE;
    return 0;
    
}

void solve() {
    string query;
    while (true) {
        cin >> query; 
        if (query == "***") break;
        else if (query == "NUMBER_PEOPLE") cout << number_people << '\n';
        else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string date; cin >> date;
            cout << number_people_born_at[date] << '\n';
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            int code; cin >> code;
            cout << generation[code] << '\n';
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date; cin >> from_date >> to_date;
            
            auto itlow = number_people_born_between.lower_bound(from_date); itlow--;
            auto itup = number_people_born_between.upper_bound(to_date); itup--;
            
            int low = itlow->second;
            int up = itup->second;
            
            cout << up - low << '\n';
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            cout << max_independent_set() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    
    return 0;
}
