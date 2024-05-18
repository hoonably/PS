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
https://www.acmicpc.net/problem/1448
3개의 빨대를 선택해서 삼각형 만들었을때 둘레의 최대값
*/

#define MAX 1'000'000

int N;
int stick[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    FOR(i,0,N){
        cin >> stick[i];
    }
    sort(stick, stick+N, greater<>());

    FOR(i,0,N-2){
        if (stick[i] < stick[i+1] + stick[i+2]){
            cout << stick[i] + stick[i+1] + stick[i+2];
            return 0;
        }
    }
    cout << "-1";
    
    return 0;
}