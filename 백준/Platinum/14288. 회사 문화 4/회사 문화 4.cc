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
https://www.acmicpc.net/problem/14288

회사 문화 4

Lazy Propagation + 오일러 투어 테크닉

*/

#define MAX 100'000

// ll arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = int;
    vector<DataType> tree;
    vector<DataType> lazy;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
        lazy.resize(treeSize);
    }

    void update_lazy(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += (e-s+1)*lazy[node];
            if (s != e) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int left, int right, DataType diff) {
        update_lazy(node, s, e);  // 기존에 lazy 값이 있음
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            tree[node] += (e-s+1) * diff;
            if (s != e) {lazy[node*2] += diff; lazy[node*2+1] += diff;}
            return;
        }
        int mid = (s + e) / 2;
        update_range(node*2, s, mid, left, right, diff);
        update_range(node*2 + 1, mid + 1, e, left, right, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    // left~right 구간합 출력
    DataType sum(int node, int s, int e, int left, int right){
        update_lazy(node, s, e);
        if (left > e || right < s) return 0;
        if (left <= s && right >= e) return tree[node];
        int mid = (s + e) / 2;
        return sum(node*2, s, mid, left, right)
        + sum(node*2 + 1, mid + 1, e, left, right);
    }

}UP(MAX), DOWN(MAX);

int N, M;
vector<int> adj[MAX+1];
int dfs_in[MAX+1];  // i번 정점에 방문한 시점 기록
int dfs_out[MAX+1];  // i번 정점을 빠져나온 시점 기록
int idx = 0;

// 이 문제는 직속상사라 par 필요 없음
void EulerTour(int now){  // (int now, int par){
    dfs_in[now] = ++idx;
    for(auto next : adj[now]){
        // if(next==par) continue;
        EulerTour(next);  // EulerTour(next, now);
    }
    dfs_out[now] = idx;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i=1; i<=N; i++){
        int p;
        cin >> p;  // 직속 상사의 번호
        if (i==1) continue;
        adj[p].push_back(i);  // p의 직속 부하가 i
    }

    EulerTour(1);

    bool check = 0;  // 부하 방향으로 칭찬
    while(M--){
        int a, b, c;
        cin >> a;
        if (a==1){
            cin >> b >> c;
            // 부하 방향 칭찬
            if (!check) DOWN.update_range(1, 1, N, dfs_in[b], dfs_out[b], c);
            // 상사 방향 칭찬
            else UP.update_range(1, 1, N, dfs_in[b], dfs_in[b], c);
        }
        else if (a==2){
            cin >> b;
            cout << UP.sum(1,1, N, dfs_in[b], dfs_out[b]) 
            + DOWN.sum(1, 1, N, dfs_in[b], dfs_in[b])<< "\n";
        }
        else check^=1;
    }
}