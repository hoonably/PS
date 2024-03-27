#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*
trie 자료구조

*/

struct Trie {
	map<string, Trie*> m;

	void insert(vector<string>& v, int idx) {
		if (idx == v.size())
			return;

        // map에 저장되어있지 않다면
		if (m.find(v[idx]) == m.end()) {
			Trie* trie = new Trie;
			m.insert({ v[idx], trie });
		}

		m[v[idx]]->insert(v, idx + 1);
	}
    
    // 원소 출력
	void dfs(int d) {
		for (auto& i : m) {
			for (int j = 0; j < d; j++)
				cout << "--";
			cout << i.first << '\n';
			i.second->dfs(d + 1);
			delete i.second;
		}
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
	cin >> n;

	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		vector<string> v(num);
		for (int j = 0; j < num; j++)
			cin >> v[j];
		root->insert(v, 0);
	}

	root->dfs(0);
	delete root;
    
    return 0;
}