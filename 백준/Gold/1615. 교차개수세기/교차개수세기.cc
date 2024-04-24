#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'001

/*
세그먼트 트리로 버블소트할때 swap이 몇번 발생할지
swap의 개수 : 자신보다 작은 수의 개수

*/

int N, M;
pii edges[2'000'000];  // 간선

struct FenwickTree {
    vector<int> tree;

    // 생성자
    FenwickTree(int n) : tree(n+1) {};

    int sum(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);  
            // pos & -pos : 가장 오른쪽에 있는 비트 1
            // pos가 1001100 이라면 100 반환
            // 이진 인덱스 트리나 펜윅 트리에서 
            // 특정 위치 이후에 오는 다음 위치를 찾는 데 사용
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    FenwickTree fwTree(2001);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    sort(edges, edges+M);

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        if (edges[i].second != N) {
            ans += fwTree.sum(N - edges[i].second);
        }
        fwTree.add(N + 1 - edges[i].second, 1);
    }
    cout << ans;
    
    return 0;
}