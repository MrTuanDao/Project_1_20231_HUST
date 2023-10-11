// Cai dat bang bfs, moi trang thai co the tao ra 6 trang thai tiep theo
#include <bits/stdc++.h>
using namespace std;

const int N = 900;

bool visited[N][N];
int d[N][N];

int main(){
    int a, b, c; cin >> a >> b >> c; 
    // cout << a << ' ' << b << ' ' << c << endl;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int dis = d[x][y];
        // cout << x << ' ' << y << endl;
        if(x == c || y == c){
            cout << d[x][y];
            return 0;
        }
        // do nuoc vao a => (a, y)
        if(!visited[a][y]){
            visited[a][y] = 1;
            d[a][y] = dis + 1;
            q.push({a, y});
            // cout << q.front().first;
        }
        // do nuoc vao b => (x, b)
        if(!visited[x][b]){
            visited[x][b] = 1;
            d[x][b] = dis + 1;
            q.push({x, b});
        }
        // do nuoc ra khoi a => (0, y)
        if(!visited[0][y]){
            visited[0][y] = 1;
            d[0][y] = dis + 1;
            q.push({0, y});
        }
        // do nuoc ra khoi b => (x, 0)
        if(!visited[x][0]){
            visited[x][0] = 1;
            d[x][0] = dis + 1;
            q.push({x, 0});
        }
        // do nuoc tu a sang b => ( max(0, x + y - b), min(x + y, b))
        if(!visited[max(0, x + y - b)][min(x + y, b)]){
            visited[max(0, x + y - b)][min(x + y, b)] = 1;
            d[max(0, x + y - b)][min(x + y, b)] = dis + 1;
            q.push({ max(0, x + y - b), min(x + y, b)});
        }
        // do nuoc tu b sang a => ( min(a, y + x), max(0, y + x - a))
        if(!visited[min(a, y + x)][max(0, y + x - a)]){
            visited[min(a, y + x)][max(0, y + x - a)] = 1;
            d[min(a, y + x)][max(0, y + x -a)] = dis + 1;
            q.push({min(a, y + x), max(0, y +x - a)});
        }
    }
    
    cout << -1;
    return 0;
}
