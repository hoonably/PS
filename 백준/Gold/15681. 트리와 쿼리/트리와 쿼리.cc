#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001


/*

*/

vector<int> v[MAX];
bool visited[MAX];
int num[MAX];
int node, query, s, e;


int dfs(int n) {
	if (num[n] != 0) return num[n];
	visited[n] = true;
	int ret = 1;
	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (visited[next]) continue;
		ret += dfs(next);
	}
	num[n] = ret;
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

	int root;
	cin >> node >> root >> query;
	for (int i = 0; i < node - 1; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	num[root] = dfs(root);
	for (int i = 0; i < query; i++) {
		cin >> s;
		cout << num[s] << '\n';
	}
	return 0;
}