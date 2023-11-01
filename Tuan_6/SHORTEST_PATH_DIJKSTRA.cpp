// Dao Quoc Tuan 20210891
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e6;
int n, m;
vector< pair<int, int> > nextNode[N];
priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > 
                min_path_sum_and_node;  // lưu trữ đường đi tới các đỉnh và đỉnh đó, 
                                        // cài đặt bằng priority_queue để nó tự sắp xếp 
                                        // theo mức độ tăng dần của đường đi

int visited[N];
int shortest_path_from_start[N];
int s, t;

void input() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   cin >> n >> m;
   for(int i = 1; i <= m; i++){
       int u, v, w; cin >> u >> v >> w;
       nextNode[u].push_back({v, w});
   }
   cin >> s >> t;
}

void djisktra() {
    memset(shortest_path_from_start, 1, sizeof(shortest_path_from_start));
    shortest_path_from_start[s] = 0; visited[s] = 1;
    int cur_node = s, cur_path_sum_w = 0, so_dinh_da_tinh = 1;
    
    while (so_dinh_da_tinh <= n) {
        so_dinh_da_tinh++;
        
        for(auto it = nextNode[cur_node].begin(); it != nextNode[cur_node].end(); it++) {
            pair<int, int> tempPair = *it;
            int next = tempPair.first, weight = tempPair.second;
            
            if (visited[next]) continue;
            
            shortest_path_from_start[next] = min( shortest_path_from_start[next], cur_path_sum_w + weight);
            min_path_sum_and_node.push({shortest_path_from_start[next], next});
        }

      // Tìm đỉnh chưa tính trong các đỉnh đã lưu
        while( visited[cur_node] && so_dinh_da_tinh <= n) {
            cur_node = min_path_sum_and_node.top().second;
            min_path_sum_and_node.pop();
        }
  
        cur_path_sum_w = shortest_path_from_start[cur_node];
        visited[cur_node] = 1;
    }
}

int main() {
    input();
    djisktra();
    
    cout << shortest_path_from_start[t];

    return 0;
}
