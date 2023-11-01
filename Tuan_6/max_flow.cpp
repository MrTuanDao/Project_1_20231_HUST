#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m;
vector<int> nextNode[N];
int dist[N][N];
int s, t;

void input() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m; 
    cin >> s >> t;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        nextNode[u].push_back(v);
        dist[u][v] = w;
    }
}

int ford_fulkerson() {
    int max_flow = 0;
    
    // Vòng lặp chính
    while (true) {
        bool visited[N + 5]; memset(visited, 0, sizeof(visited));
        int parent[N + 5]; memset(parent, -1, sizeof(parent));
        
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        
        // BFS tìm đường tăng luồng
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const int& v : nextNode[u]) {
                if (visited[v] || dist[u][v] <= 0) continue;
                
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }

        if (!visited[t]) break;
        
        // Tính giá trị tăng luồng
        int flow = INT_MAX;
        int v = t;
        while (v != s) {
            int u = parent[v];
            flow = min(flow, dist[u][v]);
            v = u;
        }
        
        // Cập nhật lại đồ thị và luồng
        v = t;
        while(v != s) {
            int u = parent[v];
            dist[u][v] -= flow;
            dist[v][u] += flow;
            v = u;
        }
        max_flow += flow;
    }
    
    return max_flow;
}

int main() {
    input();
    cout << ford_fulkerson() << endl;
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=n; j++) cout << dist[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
