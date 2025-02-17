#include <iostream>

using namespace std;

const int MAXN = 100, MAXM = 100; // Giới hạn số đỉnh và số cạnh
int adj[MAXN][MAXN];  // Ma trận kề để lưu đồ thị
int deg[MAXN];        // Bậc của từng đỉnh
int tin[MAXN], low[MAXN]; // Thời gian vào và giá trị low
bool visited[MAXN];   // Đánh dấu đỉnh đã duyệt
int timer = 0, bridgeCount = 0;
int edges[MAXM][2];   // Danh sách các cạnh (dùng để in)

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (v == parent) continue;

        if (visited[v]) {
            low[u] = (low[u] < tin[v]) ? low[u] : tin[v];
        } else {
            dfs(v, u);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (low[v] > tin[u]) {
                bridgeCount++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << "So canh cau: " << bridgeCount << endl;
    return 0;
}
