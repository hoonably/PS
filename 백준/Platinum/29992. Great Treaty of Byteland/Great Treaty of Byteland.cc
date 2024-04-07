#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1e5

int N, cnt = 0;
set<int> ans;

struct dot {
	ll x, y;
	int idx;
	bool operator<(const dot& p) const { return x == p.x ? y < p.y : x < p.x; }
};

vector<dot> C, H;

ll cross(const dot& d1, const dot& d2, const dot& d3) {
	return (d2.x - d1.x) * (d3.y - d2.y) - (d2.y - d1.y) * (d3.x - d2.x);
}

void solve() {

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	C.resize(N);

	for (int i = 0; i < N; i++) {
        cin >> C[i].x >> C[i].y;
        C[i].idx = i + 1;
    }

	vector<dot> H;
	sort(C.begin(), C.end());
	if (C.size() <= 2) {
		for (const dot& pos : C) H.push_back(pos);
	}
	else {
		for (int i = 0; i < C.size(); i++) {
			while (H.size() > 1 && cross(H[H.size() - 2], H[H.size() - 1], C[i]) < 0)
				H.pop_back();
			H.push_back(C[i]);
		}
		H.pop_back();
		int s = H.size() + 1;
		for (int i = C.size() - 1; i >= 0; i--) {
			while (H.size() > s && cross(H[H.size() - 2], H[H.size() - 1], C[i]) < 0)
				H.pop_back();
			H.push_back(C[i]);
		}
		H.pop_back();
	}

	for (dot d : H) ans.insert(d.idx);

	for (int i: ans) cout << i << " ";

	return 0; 
}