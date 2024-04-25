#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 2'000'001

/*
1 : 자연수 X 추가
2 : X번째로 작은 수 출력하고 삭제

세그먼트 트리로 구간에 있는 수의 갯수를 사용
*/

int segTree[4*MAX];

// diff가 1이라면 추가, -1이라면 삭제
void update(int node, int s, int e, int target, int diff){
    if (target > e || target < s) return;
    if (s == e){
        segTree[node] += diff;
        return;
    }
    int mid = (s + e) / 2;
    update(node*2, s, mid, target, diff);
    update(node*2 + 1, mid + 1, e, target, diff);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

// k번째 수 찾기
int find(int node, int s, int e, int k) {
	if (s == e) return s;
	int m = (s + e) / 2;
	if (k <= segTree[2 * node]) return find(2 * node, s, m, k);
	else return find(2 * node + 1, m + 1, e, k - segTree[2 * node]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    // // 트리의 크기
    // int h = ceil(log2(MAX));  // ceil : 정수로 올림
    // int treeSize = 1 << (h + 1);
    // segTree.resize(treeSize);
    
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int T, X;
        cin >> T >> X;
        if (T==1){
            update(1,1,MAX,X,1);
        }
        else {
            int del = find(1,1,MAX,X);
            cout << del << '\n';
            // update(1,1,MAX,X,-1);  // X업데이트해서 틀렸었음
            update(1,1,MAX,del,-1);
        }
    }
    
    return 0;
}