#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001


/*
서브트리의 개수를 만들면서 트리를 만드는 dfs
*/

vector<int> v[MAX];
bool visited[MAX];
int num[MAX];
int node, query, s, e;


int dfs(int now) {

	if (num[now] != 0) return num[now];
	visited[now] = true;

	int ret = 1; // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1에서 시작한다.
	for (int next : v[now]) {
		if (visited[next]) continue;
		ret += dfs(next);
	}

	num[now] = ret;

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
    
	// root 를 기준으로 트리를 생성하면서 그 서브트리의 개수 저장
	num[root] = dfs(root);

	for (int i = 0; i < query; i++) {
		cin >> s;
		cout << num[s] << '\n';
	}

	return 0;
}