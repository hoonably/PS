#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, wall;
};

int make(vector<vector<int>>& arr, int n, int m, int k) {
    queue<Node> q;
    q.push({0, 0, 0});

    int is_night = 1;
    int ans = 1;

    vector<vector<int>> visited(n, vector<int>(m, k + 1));
    visited[0][0] = 0;

    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().x;
            int y = q.front().y;
            int wall = q.front().wall;
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return ans;
            }

            for (const auto& d : direction) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (visited[nx][ny] <= wall) {
                        continue;
                    }

                    if (arr[nx][ny] == 0) {
                        q.push({nx, ny, wall});
                        visited[nx][ny] = wall;
                    } else if (wall < k) {
                        if (!is_night) {
                            q.push({x, y, wall});
                        } else {
                            visited[nx][ny] = wall;
                            q.push({nx, ny, wall + 1});
                        }
                    }
                }
            }
        }

        ans++;
        is_night ^= 1;
    }

    return -1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    int ans = make(arr, n, m, k);
    cout << ans << endl;

    return 0;
}
