#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001

/*
세그먼트 트리
N=8 -> 트리에서 8~15는 arr[0]~[7]

편의를 위해 arr[0]=0 으로 지정
*/

int N, M, K;
ll arr[MAX];
vector<ll> segTree;

ll init(int node, int start, int end) {
    if (start == end)
        return segTree[node] = arr[start];
    int mid = (start + end) / 2;
    return segTree[node] = init(node*2, start, mid) 
    + init(node*2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int target, ll diff){
    if (target > end || target < start)
        return;
    segTree[node] += diff;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(node*2, start, mid, target, diff);
    update(node*2 + 1, mid + 1, end, target, diff);
}

ll sum(int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return segTree[node];
    int mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) 
    + sum(node*2 + 1, mid + 1, end, left, right);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree = vector<ll>(treeSize);

    // arr[0]=0 으로 설정
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
            ll diff = c - arr[b];  // 새로운 수 - 기존 수
            arr[b] = c;
            update(1, 1, N, b, diff); 
        }
        // b번째수 ~ C번째 수 합 구하기
        else {
            cout << sum(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}