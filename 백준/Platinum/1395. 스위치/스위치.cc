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
https://www.acmicpc.net/problem/1395
*/

#define MAX 100'000
#define treeSZ 262144  // cout 한 결과

struct SegmentTree {

    using DataType = int;
    DataType tree[treeSZ];
    bool lazy[treeSZ];  // 스위치가 바뀌었는가?

    // SegmentTree() {  // 트리 크기 출력 후 주석처리
    //     int treeSize = 1 << ((int)ceil(log2(MAX+1)) + 1);  // ceil : 정수로 올림
    //     cout << treeSize;
    // }

    void update_lazy(int node, int s, int e) {  // lazy값이 이미 있을 때 실행
        if(lazy[node]){  // 스위치가 홀수번 눌렸을 때
            tree[node] = (e - s + 1) - tree[node];  // 전체 개수중에 반대로 뒤집기
            if(s != e){
                lazy[node*2] ^= 1;
                lazy[node*2 + 1] ^= 1;
            }
            lazy[node] ^= 1;
        }
    }

    void update_range(int node, int s, int e, int left, int right) {
        update_lazy(node, s, e);
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            // 직접 tree update
            tree[node] = (e - s + 1) - tree[node];
            if(s != e){
                lazy[node*2] ^= 1;
                lazy[node*2 + 1] ^= 1;
            }
            return;
        }
        int mid = (s + e) >> 1;
        update_range((node<<1), s, mid, left, right);
        update_range((node<<1)+1, mid+1, e, left, right);
        tree[node] = tree[(node<<1)] + tree[(node<<1)+1];
    }

    // left~right 구간합 출력
    DataType sum(int node, int s, int e, int left, int right){
        update_lazy(node, s, e);
        if (left > e || right < s) return 0;
        if (left <= s && right >= e) return tree[node];
        int mid = (s + e) >> 1;
        return sum((node<<1), s, mid, left, right)
        + sum((node<<1) + 1, mid + 1, e, left, right);
    }

}ST;

int N, M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    while(M--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a==0){
            // Ab ~ Ac 스위치 켜기
            ST.update_range(1, 1, N, b, c);
        }
        else {
            cout << ST.sum(1, 1, N, b, c) << "\n";
        }
    }
}