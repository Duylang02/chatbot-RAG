#include <iostream>
using namespace std;

const int MAX = 100;
int n;
int adj[MAX][MAX]; // Ma trận kề
int state[MAX];    // 0: chưa thăm, 1: đang thăm, 2: đã thăm
bool inCycle[MAX]; // Đánh dấu đỉnh thuộc chu trình

void dfs(int u) {
    state[u] = 1; // Đánh dấu là đang thăm
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) { // Nếu có cạnh u -> v
            if (state[v] == 1) { // Nếu gặp đỉnh đang thăm -> phát hiện chu trình
                inCycle[v] = true;
                inCycle[u] = true;
            } else if (state[v] == 0) {
                dfs(v);
                if (inCycle[v]) inCycle[u] = true; // Nếu v thuộc chu trình thì u cũng thuộc
            }
        }
    }
    state[u] = 2; // Đánh dấu là đã thăm xong
}

int main() {
    cin >> n;
    
    // Nhập ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Khởi tạo trạng thái
    for (int i = 0; i < n; i++) {
        state[i] = 0;
        inCycle[i] = false;
    }

    // Chạy DFS từ mỗi đỉnh chưa được thăm
    for (int i = 0; i < n; i++) {
        if (state[i] == 0) dfs(i);
    }

    // In các đỉnh không thuộc chu trình
    for (int i = 0; i < n; i++) {
        if (!inCycle[i]) cout << i << " ";
    }

    return 0;
}
