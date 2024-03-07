#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

pair<int, char> DSLR(int num, int command) {
    if (command == 0) {
        return { (num * 2) % 10000, 'D' };
    }

    if (command == 1) {
        if (num == 0) {
            return { 9999, 'S' };
        }
        return { num - 1, 'S' };
    }

    if (command == 2) {
        num = num % 1000 * 10 + num / 1000;
        return { num, 'L' };
    }

    if (command == 3) {
        int temp = num % 10;
        int temp2 = num / 10;
        num = temp * 1000 + temp2;
        return { num, 'R' };
    }
}

string bfs(int start_node, int end_node) {
    queue<int> q;
    q.push(start_node);
    
    vector<bool> visited(10001, false);
    visited[start_node] = true;

    vector<string> path(10001, "");

    while (!q.empty()) {
        int curr_node = q.front();
        q.pop();

        if (curr_node == end_node) {
            return path[curr_node];
        }

        for (int i = 0; i < 4; ++i) {
            // auto [next_node, command] = DSLR(curr_node, i);
            auto result = DSLR(curr_node, i);
            int next_node = result.first;
            char command = result.second;
            if (visited[next_node] == false) {
                visited[next_node] = true;
                q.push(next_node);
                path[next_node] = path[curr_node] + command;
            }
        }
    }

    return ""; // If no path is found
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;

    while(T--) {
        int A, B;
        cin >> A >> B;
        cout << bfs(A, B) << '\n';
    }

    return 0;
}
