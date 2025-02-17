#include <iostream>

using namespace std;

const int MAXN = 100;
int maze[MAXN][MAXN];    // Ma trận bản đồ (0: đường đi, 1: tường)
int dist[MAXN][MAXN];    // Lưu khoảng cách từ điểm xuất phát
bool visited[MAXN][MAXN];// Đánh dấu ô đã duyệt
int parent[MAXN][MAXN];  // Lưu vị trí trước đó để truy vết đường đi
int que[MAXN * MAXN][2]; // Hàng đợi dùng mảng tĩnh

// 4 hướng di chuyển (trái, phải, lên, xuống)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Mã hóa vị trí (x, y) thành 1 số nguyên
int encode(int x, int y, int m) {
    return x * m + y;
}

// Giải mã số nguyên thành vị trí (x, y)
void decode(int code, int &x, int &y, int m) {
    x = code / m;
    y = code % m;
}

// BFS để tìm đường đi ngắn nhất
int bfs(int n, int m, int sx, int sy, int ex, int ey) {
    int front = 0, back = 0;
    que[back][0] = sx;
    que[back++][1] = sy;
    visited[sx][sy] = true;
    dist[sx][sy] = 0;
    parent[sx][sy] = -1; // Điểm bắt đầu không có cha

    while (front < back) {
        int x = que[front][0];
        int y = que[front++][1];

        if (x == ex && y == ey) return dist[x][y]; // Tìm thấy đích

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] == 0) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = encode(x, y, m); // Lưu lại cha của ô này
                que[back][0] = nx;
                que[back++][1] = ny;
            }
        }
    }
    return -1; // Không tìm thấy đường đi
}

// Truy vết đường đi từ đích ngược về xuất phát
void printPath(int ex, int ey, int sx, int sy, int m) {
    int x = ex, y = ey;
    int path[MAXN * MAXN][2], pathLen = 0;

    while (x != sx || y != sy) {
        path[pathLen][0] = x;
        path[pathLen++][1] = y;
        int prev = parent[x][y];
        decode(prev, x, y, m);
    }
    path[pathLen][0] = sx;
    path[pathLen++][1] = sy;

    // In đường đi theo thứ tự ngược lại
    for (int i = pathLen - 1; i >= 0; i--) {
        cout << "(" << path[i][0] << "," << path[i][1] << ") ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập kích thước ma trận

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j]; // 0: đường, 1: tường
        }
    }
    cin >> sx >> sy >> ex >> ey; // Nhập điểm bắt đầu và kết thúc

    int result = bfs(n, m, sx, sy, ex, ey);
    if (result == -1) {
        cout << "Khong co duong di" << endl;
    } else {
        cout << "Do dai duong di: " << result << endl;
        printPath(ex, ey, sx, sy, m);
    }

    return 0;
}
