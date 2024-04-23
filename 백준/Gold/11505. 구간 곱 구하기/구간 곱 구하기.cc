#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001
#define MOD 1'000'000'007

/*
세그먼트 트리
구간 곱 구해서 MOD로 나눈 나머지 구하기
*/

int N, M, K;
ll arr[MAX];
vector<ll> segTree;

ll init(int node, int start, int end) {
    if (start == end)
        return segTree[node] = arr[start];
    int mid = (start + end) / 2;
    return segTree[node] = init(node*2, start, mid) 
    * init(node*2 + 1, mid + 1, end) % MOD;
}

void update(int node, int start, int end, int idx, ll value){
    if (idx < start || end < idx) return;
 
    if (start == end){
        segTree[node] = value;
        return;
    }
 
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    segTree[node] = (segTree[node * 2] * segTree[node * 2 + 1]) % MOD;
}

ll multiple(int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return 1;  // 곱이기 때문에
    if (left <= start && right >= end)
        return segTree[node];
    int mid = (start + end) / 2;
    return multiple(node*2, start, mid, left, right) 
    * multiple(node*2 + 1, mid + 1, end, left, right) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree = vector<ll>(treeSize);

    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    init(1, 1, N);

    for (int i=0; i<M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        // b번째 수를 c로 변경
        if (a==1){
            arr[b] = c;
            update(1, 1, N, b, c); 
        }
        // b번째수 ~ C번째 수 곱 구하기
        else {
            cout << multiple(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}