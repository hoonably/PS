#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'001

/*
펜윅 트리 사용
펜윅트리는 세그먼트트리를 응용한 자료구조라고 볼 수 있다.
1번 부터 현재 Index까지의 연산 결과를 저장하는 '누적'개념을 사용

메모리가 훨씬 더 절약되고, 코드가 간결하고 짧다는 장점

구간에 대한 연산결과가 아닌, 특정 값만을 찾기를 원한다면 
펜윅트리는 구현이 힘들다.
ex) 최댓값 or 최솟값 찾기

*/

int N, M, K;
pii edges[400'000];  // 고속도로

struct FenwickTree {
    vector<int> tree;

    // 생성자
    FenwickTree(int n) : tree(n+1) {};

    // 1 ~ idx번 누적합 구하기
    int sum(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx &= (idx - 1);
        }
        return ret;
    }
    
    void update(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += (idx & -idx); 
            // idx & -idx : 1이 존재하는 '최하위' 있는 비트
            // pos가 1001100 이라면 100 반환
            // 이진 인덱스 트리나 펜윅 트리에서 
            // 특정 위치 이후에 오는 다음 위치를 찾는 데 사용
        }
    }

    void makeTree(int arr[]){
        for (int i=1; i<=N; i++){
            update(i, arr[i]);
        }
    }
};

ll solve(){
    int N, M, K;
    cin >> N >> M >> K;

    FenwickTree fwTree(1001);

    for (int i = 0; i < K; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    sort(edges, edges+K);

    ll ans = 0;
    for (int i = 0; i < K; i++) {
        if (edges[i].second != M) {
            ans += fwTree.sum(M - edges[i].second);
        }
        fwTree.update(M + 1 - edges[i].second, 1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        cout << "Test case " << i << ": ";
        cout << solve() << '\n';
    }
    
    return 0;
}