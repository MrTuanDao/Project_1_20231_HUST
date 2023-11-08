#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int number_transactions = 0, total_money_transaction = 0; 
set<string> list_sorted_accounts;
map<string, int> total_money_transaction_from;
map<string, set<string> > connected_accounts;
map<string, bool> visited;
int k, inspect_cycle;
string root_account;

void dfs(string account, int step) {
    // cout << account << ' ' << step << endl;
    if (!inspect_cycle)
    for (const string& next_account : connected_accounts[account]) {
        if (inspect_cycle) break;
        // cout << "next_account: " << next_account << ' ' << visited[next_account] << endl;
        if (step == k && next_account == root_account) {
            inspect_cycle = 1; break;
        }
        if (visited[next_account] == 1) continue;
        
        visited[account] = 1;
        
        if (step <= k) dfs(next_account, step + 1);
        
        visited[account] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string from_account, to_account,time_point, atm; int money;
    while (true) {
        cin >> from_account; if (from_account == "#") break;
        cin >> to_account >> money >> time_point >> atm;
        
        number_transactions++;
        total_money_transaction += money;
        list_sorted_accounts.insert(from_account);
        list_sorted_accounts.insert(to_account);
        total_money_transaction_from[from_account] += money;
        if(to_account != from_account) {
            connected_accounts[from_account].insert(to_account);
        }
    }
    
    string query;
    while (true) {
        cin >> query; 
        if (query == "#") break;
        else if (query == "?number_transactions") cout << number_transactions << '\n';
        else if (query == "?total_money_transaction") cout << total_money_transaction << '\n';
        else if (query == "?list_sorted_accounts") {
            for (const string& account : list_sorted_accounts) cout << account << ' ';
            cout << '\n';
        }
        else if (query == "?total_money_transaction_from") {
            string account; cin >> account;
            cout << total_money_transaction_from[account] << '\n';
        }
        else if (query == "?inspect_cycle") {
            cin >> root_account >> k; inspect_cycle = 0; visited[root_account] = 1;
            dfs(root_account, 1);
            visited[root_account] = 0;
            
            cout << inspect_cycle << '\n';
        }
    }
    
    return 0;   
}
