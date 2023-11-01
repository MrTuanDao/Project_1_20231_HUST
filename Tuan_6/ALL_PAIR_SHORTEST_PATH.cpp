#include<bits/stdc++.h>
using namespace std;
// Floyed-Warshall
const int N = 1e4 + 5;
int n, m, table[N][N];

int main(){
    cin >> n >> m;
    memset(table, 1, sizeof(table));
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        table[u][v] = w;
    }
    for(int i = 1 ; i <= n ; ++i) table[i][i] = 0;

    for(int k = 1 ; k <= n ; ++k)
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j)
    table[i][j] = min(table[i][j], table[i][k] + table[k][j]);

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j) cout << table[i][j] << " ";
        cout << endl;
    }

    return 0;
}
