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
https://www.acmicpc.net/problem/30805

생각보다 까다로웠던 문제.
9 8 9 가 lcs라면
8 다음에 9가 나올때 8을 지워서 답을 9로 만들어서 틀렸었음
정답은 9 8 임
*/

#define MAX 101

bool cmp(pii A, pii B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first > B.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

	int N, M;
	cin >> N;

	vector<pii> A, B;
 	for (int i = 0, v; i < N; i++) {
		cin >> v;
		A.push_back({ v, i });
	}
	cin >> M;
	for (int i = 0, v; i < M; i++) {
		cin >> v;
		B.push_back({ v, i });
	}

	vector<int> ans;
	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);

	int i = 0, j = 0, limita=0, limitb=0;
	while (i < N && j < M) {
		if (A[i].first == B[j].first) {
			if (limita > A[i].second) i++;
			else if (limitb > B[j].second) j++;
			else {
				limita = A[i].second;
				limitb = B[j].second;
				ans.emplace_back(A[i].first);
				i++;
				j++;
			}
		}
		else if (A[i].first > B[j].first) i++;
		else j++;
	}

	cout << ans.size() << "\n";
	for (int num : ans) cout << num << " ";
	return 0;
}