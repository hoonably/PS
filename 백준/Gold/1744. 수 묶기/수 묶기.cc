#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*
음수와 양수는 묶으면 X
음수 ~ 0 은 순서대로 묶기

예외처리
1 이 있다면 곱하지 않고 합하는게 좋음
*/

int N;

// 최대 힙 (큰 거부터 뽑힘)
priority_queue<int> pq;

// 최소 힙 (작은 거부터 뽑힘)
priority_queue<int, vector<int>, greater<int>> pq2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int ans = 0;

    cin >> N;

    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        if (num>=2) pq.push(num);
        else if (num==1) ans++;
        else pq2.push(num);
    }

    while (!pq.empty()){
        int temp = pq.top();
        pq.pop();

        // 홀수번째로 끝난다면
        if (pq.empty()) {
            ans += temp;
            break;
        }

        ans += temp * pq.top();
        pq.pop();
    }

    while (!pq2.empty()){
        int temp = pq2.top();
        pq2.pop();

        // 홀수번째로 끝난다면
        if (pq2.empty()) {
            ans += temp;
            break;
        }

        ans += temp * pq2.top();
        pq2.pop();
    }

    cout << ans;
    
    return 0;
}