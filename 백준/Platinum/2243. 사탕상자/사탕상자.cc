#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


/*
세그먼트 트리
https://www.acmicpc.net/problem/2243
사탕 상자


*/

#define MAX 1'000'001

ll segTree[MAX*4];

// idx 인덱스의 숫자를 diff만큼 변화
void update(int node, int s, int e, int idx, ll diff){
    if (idx < s || idx > e) return;
    segTree[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node*2, s, mid, idx, diff);
    update(node*2 + 1, mid + 1, e, idx, diff);
}

// k번째로 맛있는 사탕의 맛 반환
ll query(int node, int s, int e, int k){
    if (s==e) return e;
    int mid = (s + e) / 2;
    if (segTree[node*2] >= k) return query(node*2, s, mid, k);
    else return query(node*2+1, mid+1, e, k-segTree[node*2]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, A, B, C;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A;
        if (A==1) {
            // B번째 사탕 꺼내기
            cin >> B;
            int taste = query(1, 1, MAX, B);
            cout << taste << '\n';
            // 꺼낸거 update
            update(1, 1, MAX, taste, -1);
        }
        else {
            // B맛 사탕 C개 넣거나 빼기
            cin >> B >> C;
            update(1, 1, MAX, B, C);
        }
    }
    
    return 0;
}