#include <bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string>> adj;
unordered_map<string, bool> visited;
vector<string> ans;

void dfs(string s) {
    if (visited[s]) return;
    visited[s] = true;
    ans.emplace_back(s);
    for (string next: adj[s]) {
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string p, is, q;
        cin >> p >> is >> q;
        adj[p].emplace_back(q);
    }
    dfs("Baba");
    sort(ans.begin(), ans.end());
    for (auto p: ans) if (p != "Baba") cout << p << '\n';
}