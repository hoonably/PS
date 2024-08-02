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
https://www.acmicpc.net/problem/18227

성대나라의 물탱크

Lazy Propagation 사용 안함
세그먼트 트리 + 오일러 투어 테크닉


*/

#define MAX 200'000

// ll arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = long long;
    vector<DataType> tree;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
    }

    // idx 인덱스의 숫자를 diff "만큼" 변화
    void updateDiff(int node, int s, int e, int idx, DataType diff){
        if (idx > e || idx < s) return;
        tree[node] += diff;
        if (s == e) return;
        int mid = (s + e) / 2;
        updateDiff(node*2, s, mid, idx, diff);
        updateDiff(node*2 + 1, mid + 1, e, idx, diff);
    }

    // idx 인덱스의 숫자를 value "로" 변화
    void updateValue(int node, int s, int e, int idx, DataType value){
        if (idx > e || idx < s) return;
        if (s == e) {
            tree[node] = value; return;
        }
        int mid = (s + e) / 2;
        updateValue(node*2, s, mid, idx, value);
        updateValue(node*2 + 1, mid + 1, e, idx, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // left~right 구간합
    DataType sum(int node, int s, int e, int left, int right){
        if (left > e || right < s)
            return 0;
        if (left <= s && right >= e)
            return tree[node];
        int mid = (s + e) / 2;
        return sum(node*2, s, mid, left, right) 
        + sum(node*2 + 1, mid + 1, e, left, right);
    }
}ST(MAX);

int N, C, Q;
vector<int> adj[MAX+1];
int depth[MAX+1];  // i번 정점의 깊이
int dfs_in[MAX+1];  // i번 정점에 방문한 시점 기록
int dfs_out[MAX+1];  // i번 정점을 빠져나온 시점 기록
int idx = 0;

// 이 문제는 직속상사라 par 필요 없음
void EulerTour(int now){  // (int now, int par){
    dfs_in[now] = ++idx;
    for(auto next : adj[now]){
        if (depth[next]==0){
            depth[next]=depth[now]+1;
            EulerTour(next);  // EulerTour(next, now);
        }
    }
    dfs_out[now] = idx;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> C;
    for (int i=1; i<=N-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    depth[C]=1;
    EulerTour(C);  // 수도가 Root

    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;;
        if (a==1){
            ST.updateDiff(1, 1, N, dfs_in[b], 1);
        }
        else {
            cout << ST.sum(1, 1, N, dfs_in[b], dfs_out[b]) * depth[b] << "\n";
        }
    }
}