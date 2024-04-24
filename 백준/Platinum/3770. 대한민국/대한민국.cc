#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'001

/*
세그먼트 트리로 버블소트할때 swap이 몇번 발생할지
swap의 개수 : 자신보다 작은 수의 개수

*/

int N, M, K;
int arr[MAX];

struct FenwickTree {
    vector<int> tree;

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

ll solve(){
    vector<pair<int, int>> edges;

    int N, M, K;
    cin >> N >> M >> K;

    FenwickTree fwt(1001);

    for (int i = 0; i < K; i++) {
        int s, e;
        cin >> s >> e;
        edges.push_back({s, e});
    }

    sort(edges.begin(), edges.end());

    ll ans = 0;
    for (int i = 0; i < K; i++) {
        if (edges[i].second != M) {
            ans += fwt.sum(M - edges[i].second);
        }
        fwt.add(M + 1 - edges[i].second, 1);
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