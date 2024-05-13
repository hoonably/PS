#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/2457

*/


#define MAX 100'000

int N;
pii flowers[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        // 6 30 이면 630 되도록
        int month, day;
        cin >> month >> day;
        flowers[i].first = month*100 + day;
        cin >> month >> day;
        flowers[i].second = month*100 + day;
    }

    // 시작 날짜 기준으로 정렬
    sort(flowers, flowers+N);

    // 이어야하기 때문에 최소 시작 날짜 지정
    int last = 301;
    int idx = 0;

    int cnt = 0;
    while(true){
        // 피는 시각이 지난번 지는 시간인 last보다 작거나 같을 때
        // 새 꽃이 지는 시간이 제일 늦은거 고르기
        int newLast = 0;
        while(idx<N){
            if (flowers[idx].first > last) break;
            newLast = max(newLast, flowers[idx].second);
            idx++;
        }

        cnt++;

        // 11월 30일까지 만들었음
        if (newLast > 1130){
            cout << cnt;
            break;
        }

        // 아무것도 last보다 작은 시작지점이 없음 -> 못이음
        if (newLast==0){
            cout << 0;
            break;
        }

        last = newLast;
    }
    
    return 0;
}