#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
구간 곱 세그먼트 트리
https://www.acmicpc.net/problem/11505
*/

#define MAX 1'000'000

ll arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = long long;
    vector<DataType> tree;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
    }

    // 미리 정해놓은 배열로 세그트리 구성
    DataType build(int node, int s, int e) {  // 인덱스 따라서 (1, 1, N) / (0, 0, N-1)
        if (s == e)
            return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = build(node*2, s, mid) * build(node*2 + 1, mid + 1, e) % MOD;
    }

    // idx 인덱스의 숫자를 value "로" 변화
    void update(int node, int s, int e, int idx, DataType value){
        if (idx > e || idx < s) return;
        if (s == e) {
            tree[node] = value; return;
        }
        int mid = (s + e) / 2;
        update(node*2, s, mid, idx, value);
        update(node*2 + 1, mid + 1, e, idx, value);
        tree[node] = tree[node * 2] * tree[node * 2 + 1] % MOD;
    }

    // left~right 구간곱 구하기
    DataType multiple(int node, int s, int e, int left, int right){
        if (left > e || right < s)
            return 1;  // 곱이기 때문에
        if (left <= s && right >= e)
            return tree[node];
        int mid = (s + e) / 2;
        return multiple(node*2, s, mid, left, right) 
        * multiple(node*2 + 1, mid + 1, e, left, right) % MOD;
    }
}ST(MAX);
 
int N, M, K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    ST.build(1, 1, N);

    for (int i=0; i<M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        // b번째 수를 c로 변경
        if (a==1){
            arr[b] = c;
            ST.update(1, 1, N, b, c); 
        }
        // b번째수 ~ C번째 수 곱 구하기
        else {
            cout << ST.multiple(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}