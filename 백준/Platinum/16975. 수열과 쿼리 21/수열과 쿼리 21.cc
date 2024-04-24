#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'001

/*
Lazy Propagation 을 사용하지 않고 세그먼트 트리만을 이용하여 풀이

*/

int arr[MAX];
vector<ll> segTree;

void init(int node, int s, int e) {
    if (s == e){
        segTree[node] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    init(node*2, s, mid);
    init(node*2 + 1, mid + 1, e);
}

// l~r 번에 num 더해주기
void update(int node, int s, int e, int l, int r, int num) {
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        segTree[node] += num;
        return;
    }
    int mid = (s + e) / 2;
    update(2 * node, s, mid, l, r, num);
    update(2 * node + 1, mid + 1, e, l, r, num);
}

ll query(int node, int s, int e, int idx, ll ans) {
    if (e < idx || idx < s) return 0;
    ans += segTree[node];
    if (s == e) return ans;
    int mid = (s + e) / 2;
    return query(2 * node, s, mid, idx, ans) + query(2 * node + 1, mid + 1, e, idx, ans);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    init(1, 1, N);

    cin >> M;
    for (int i=0; i<M; i++){
        int q;
        cin >> q;
        if (q==1){
            int a, b, k;  // Aa ~ Ab 에 k를 모두 더한다
            cin >> a >> b >> k;
            update(1, 1, N, a, b, k);
        }
        else {
            int x;  // Ax 출력
            cin >> x;
            cout << query(1, 1, N, x, 0) << "\n";
        }
    }
    
    return 0;
}