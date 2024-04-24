#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 500'001

/*
세그먼트 트리로 버블소트할때 swap이 몇번 발생할지
swap의 개수 : 자신보다 작은 수의 개수

pair을 사용하여 second에 인덱스를 찾는다.
*/

int N;
int id_to_idx[1'000'001];  // 기계의 식별번호 0 이상 1,000,000 이하
int arr[MAX];
vector<int> segTree;

int query(int idx, int s, int e, int target) {
	if (e < target) return 0;
	if (target <= s) return segTree[idx];
	if (s == e) return segTree[idx];

	int lsum = query(idx * 2, s, (s + e) / 2, target);
	int rsum = query(idx * 2 + 1, (s + e) / 2 + 1, e, target);
	return lsum + rsum;
}

void update(int idx, int s, int e, int target) {
	if (target < s || e < target) return;
	if (s == e) {
		segTree[idx] = 1;
		return;
	}
	update(idx * 2, s, (s + e) / 2, target);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, target);
	segTree[idx]++;
}

int main() {
	int N;
	cin >> N;

    // 트리의 크기
    int h = ceil(log2(N));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

	int id;
	for (int i = 0; i < N; i++) {
		cin >> id;
		id_to_idx[id] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> id;
		arr[i] = id_to_idx[id];
	}

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += query(1, 0, N - 1, arr[i]);
		update(1, 0, N - 1, arr[i]);
	}

	cout << ans;
}