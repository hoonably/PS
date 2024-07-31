#include <bits/stdc++.h>
#define all(v) v.begin(), v.e()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
Lazy Propagation
https://www.acmicpc.net/problem/10999
*/

#define MAX 500'000

ll arr[MAX];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = int;
    vector<DataType> tree;
    vector<DataType> lazy;

    SegmentTree(int size) {
        int h = ceil(log2(size));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
        lazy.resize(treeSize);
    }

    // 미리 정해놓은 배열로 세그트리 구성
    DataType build(int node, int s, int e) {  // arr 인덱스 따라서 (1, 1, N) / (0, 0, N-1)
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = build(node*2, s, mid) ^ build(node*2 + 1, mid + 1, e);
    }

    void update_lazy(int node, int s, int e) {  // lazy값이 이미 있을 때 실행
        if ((e-s+1)%2) tree[node] ^= lazy[node];  // XOR 홀수번 일때만 한번 해주기
        if (s != e) lazy[node*2] ^= lazy[node], lazy[node*2+1] ^= lazy[node];
        lazy[node] = 0;
    }

    void update_range(int node, int s, int e, int left, int right, DataType diff) {
        if (lazy[node]) update_lazy(node, s, e);
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            // 직접 tree update
            if ((e-s+1)%2) tree[node] ^= diff;  // XOR 홀수번 일때만 한번 해주기
            if (s != e) lazy[node*2] ^= diff, lazy[node*2+1] ^= diff;
            return;
        }
        int mid = (s + e) / 2;
        update_range(node*2, s, mid, left, right, diff);
        update_range(node*2+1, mid+1, e, left, right, diff);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }

    // left~right 구간 XOR 출력
    DataType getXOR(int node, int s, int e, int left, int right){
        if (lazy[node]) update_lazy(node, s, e);
        if (left > e || right < s) return 0;
        if (left <= s && right >= e) return tree[node];
        int mid = (s + e) / 2;
        return getXOR(node*2, s, mid, left, right)
        ^ getXOR(node*2 + 1, mid + 1, e, left, right);
    }

}ST(MAX);

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    ST.build(1, 0, N-1);

    cin >> M;
    while(M--){
        int a, b, c, d;
        cin >> a;
        if (a==1){
            cin >> b >> c >> d;  // Ab ~ Ac 에 d를 XOR
            ST.update_range(1, 0, N-1, b, c, d);
        }
        else {
            cin >> b >> c;  // Ab ~ Ac 를 모두 XOR한 값을 출력
            cout << ST.getXOR(1, 0, N-1, b, c) << "\n";
        }
    }
}