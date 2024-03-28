#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 300001


/*
그리디 알고리즘의 좋은 문제
가방의 용량이 주어졌을 때 담을 수 있는 물품중에 가장 가치가 높은 물품을 담는다.
*/

int N, K;
pii V[MAX];
int C[MAX];
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> V[i].first >> V[i].second;
    }
    for (int i=0; i<K; i++){
        cin >> C[i];
    }

    // 무게 순으로 정렬
    sort(V, V+N);
    sort(C, C+K);
    
    int idx = 0;
    ll sum = 0;

    // 작은 가방부터 최적의 가치를 넣기
    for (int i = 0; i < K; i++) {

        // 넣을 수 있는 것들 pq에 일단 넣기
        while (idx < N) {
            if (C[i] < V[idx].first) break;  // 못담는 무게 나오면
            pq.push(V[idx].second);
            idx++;
        }

        // 넣을 수 있는 것중에 가치가 가장 높은 물건 넣기
        // 나머지는 그대로 저장하는게 중요
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

    return 0;
}