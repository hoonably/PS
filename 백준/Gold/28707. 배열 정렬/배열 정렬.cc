#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/28707
생각해내기 어려워서 참고함
*/

#define MAX 

typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    vi A(N);
    for (int& i : A) cin >> i;

    int M; cin >> M;
    vector<tiii> Q(M);
    for (auto& [l, r, c] : Q){
        cin >> l >> r >> c;
        l--, r--;
    }

    // 최대 우선순위 큐
    priority_queue<pair<int, vi>, vector<pair<int, vi>>, greater<pair<int, vi>>> pq; pq.push({0, A});
    map<vi, int> dist;
    dist[A] = 0;

    // 다익스트라
    while (!pq.empty()){
        auto [cost, nowVec] = pq.top(); pq.pop();
        if (dist[nowVec] < cost) continue;
        for (auto [l, r, c]: Q){
            swap(nowVec[l], nowVec[r]); // 조작
            if (dist.find(nowVec) == dist.end() || dist[nowVec] > cost + c){
                dist[nowVec] = cost + c;
                pq.push({cost + c, nowVec});
            }
            swap(nowVec[l], nowVec[r]); // 조작 전으로
        }
    }

    // 주어진 배열을 정렬한 다음, 결과가 저장되어 있는지 확인한다.
    sort(A.begin(), A.end());
    if (dist.find(A) == dist.end()) cout << -1;
    else cout << dist[A];
    
    return 0;
}