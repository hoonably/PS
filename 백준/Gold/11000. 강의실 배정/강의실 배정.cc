#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 200001

/*

*/

int N;
pii C[MAX];

// 최소 힙
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> C[i].first >> C[i].second;
    }

    // 시작 시간을 기준으로 정렬
    sort(C, C+N);


    // 최소 힙으로 끝나는 시간이 작은게 top으로

    pq.push(C[0].second);  // 첫번째는 그냥 넣어주기

    for (int i=1; i<N; i++){
        // 이전에 저장된 끝나는 시간 중에서 
        // 가장 빠른 것에 이을 수 있다면 변경해주기
        if (C[i].first >= pq.top()){
            pq.pop();
            pq.push(C[i].second);
        }
        else pq.push(C[i].second);
    }

    cout << pq.size();

    return 0;
}