#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 1001
#define MAX_M 1001
#define MAX_K 11

struct Node {
    int x, y, chance, dist;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(int start_x, int start_y, int end_x, int end_y, int n, int m, int k, vector<vector<int>>& graph) {
    vector<vector<vector<bool>>> visited(k + 1, vector<vector<bool>>(n, vector<bool>(m, false)));

    visited[0][start_x][start_y] = true;

    queue<Node> q;
    q.push({start_x, start_y, 0, 1});

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int chance = current.chance;
        int dist = current.dist;

        if (x == end_x && y == end_y) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, n, m)) {
                if (graph[nx][ny] == 0 && !visited[chance][nx][ny]) {
                    visited[chance][nx][ny] = true;
                    q.push({nx, ny, chance, dist + 1});
                } else if (graph[nx][ny] == 1 && chance < k && !visited[chance + 1][nx][ny] && dist % 2 == 1) {
                    q.push({nx, ny, chance + 1, dist + 1});
                    visited[chance + 1][nx][ny] = true;
                }
            }
        }

        if (dist % 2 == 0) {
            q.push({x, y, chance, dist + 1});
        }
    }

    return -1;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> graph(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < M; j++) {
            graph[i][j] = input[j] - '0';
        }
    }

    cout << bfs(0, 0, N - 1, M - 1, N, M, K, graph) << endl;

    return 0;
}
