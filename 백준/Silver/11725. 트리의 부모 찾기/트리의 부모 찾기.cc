#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

#define MAX 100001

int N;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];

void dfs(int s, int p) {
	parent[s] = p;

	for (auto i : tree[s]) {
		if (i == p) continue;
		dfs(i, s);
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    dfs(1,-1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
    
    return 0;
}