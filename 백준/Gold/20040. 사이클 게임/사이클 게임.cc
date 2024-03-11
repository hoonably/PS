#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

/*

*/
int n, m;
int parent[MAX];

// 부모 노드를 찾는 함수
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 작은 부모 노드의 값으로 초기화 (작은것을 항상 부모 노드로)
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

	for (int i=1; i<=m; i++) {
        int a, b;
		cin >> a >> b;

        // a와 b의 부모가 같은가?
		if (getParent(a) == getParent(b)) {
			cout << i;
			return 0;
		}
		unionParent(a, b);
	}
	cout << 0;

    return 0;
}