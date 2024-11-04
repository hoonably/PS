#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

struct TwoSat {
	int n, var;
	int vcnt;
	vector<int> v;
	vector<vector<int>> graph;  // 정방향 그래프
	vector<vector<int>> grev;  // 역방향 그래프

    TwoSat(int var_){
        var = var_;
		n = var_ * 2;
		vcnt = 0;
		v.resize(n); graph.resize(n); grev.resize(n);
    }

	void init(int var_) {
		var = var_;
		n = var_ * 2;
		vcnt = 0;
		v.clear(); v.resize(n);
		graph.resize(n); grev.resize(n);
	}
	int negation(int nod) {
		return nod >= var ? nod - var : nod + var;
	}
	// p implies q. p -> q
	void add(int p, int q) {
		graph[p].push_back(q);
		graph[negation(q)].push_back(negation(p));
		grev[q].push_back(p);
		grev[negation(p)].push_back(negation(q));
	}
	// p or q
	void addCNF(int p, int q) {
		add(negation(p), q);  // !p -> q 사용
	}
	vector<int> emit;
	void dfs1(int nod) {  // 정방향 그래프 DFS
		v[nod] = vcnt;
		for (int next : graph[nod]) {
			if (v[next] == vcnt) continue;
			dfs1(next);
		}
		emit.push_back(nod);
	}
	void dfs2(int nod) {
		v[nod] = vcnt;
		for (int next : grev[nod]) {
			if (v[next] == vcnt) continue;
			dfs2(next);
		}
		emit.push_back(nod);
	}
	bool solve() {
		++vcnt;
		emit.clear();
		for (int i = 0; i < n; i++) {
			if (v[i] == vcnt) continue;
			dfs1(i);
		}
		++vcnt;
		vector<int> scc_check(n);
		int scc_index = 0;
		for (auto start : vector<int>(emit.rbegin(), emit.rend())) {  // 역방향 iterator rbegin, rend
			if (v[start] == vcnt) continue;
			emit.clear();
			dfs2(start);
			++scc_index;
			for (auto node : emit) {
				scc_check[node] = scc_index;
				// 같은 SCC에 p와 !p가 모두 참 => 불가능
				if (scc_check[negation(node)] == scc_index) return false;
			}
		}
		return true;
	}
};

int N, M;

void solve(){
    TwoSat ts(M+1);
    while(N--){
        int i, j;
        cin >> i >> j;
        if (i<0) i = ts.negation(-i);
        if (j<0) j = ts.negation(-j);

        // i, j 동시에 만족하면 안됨
        // not(i and j) = not i or not j
        ts.addCNF(ts.negation(i), ts.negation(j));  // 둘중 하나는 아니어야함
    }
    cout << ts.solve() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    

    while(true){
        cin >> N >> M;
        if (N&&M) solve();
        else break;
    }
    
    return 0;
}