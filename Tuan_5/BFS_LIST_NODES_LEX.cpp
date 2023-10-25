// Dao Quoc Tuan 20210891
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m;
set<int> nutKe[N]; // lưu trữ tập các nút kề
int visited[N];

int main(){
    cin >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        nutKe[x].insert(y);
        nutKe[y].insert(x);
    }
    
    for(int i = 1; i <= n; i++){ // lặp qua từng nút và bfs từ nút đó
        if (visited[i]) continue;
        //bfs
        queue<int> q;
        visited[i] = 1;
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            cout << cur << ' ';
            for(auto it = nutKe[cur].begin(); it != nutKe[cur].end(); it++){
                int nut = *it;
                if(visited[nut]) continue;
                visited[nut] = 1;
                q.push(nut);
            }
        }
    }
    return 0;
}
