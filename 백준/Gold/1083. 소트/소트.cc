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

*/

#define MAX 

int N;
int A[50];
int S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> S;

    int left = 0;
    while(left < N && S>0){
        pii maximum = {A[left], left};

        // S번 내로 끌어 올릴 수 있는 
        // 가장 큰 값이 있는 인덱스 찾기
        for (int i=left+1; i<=min(left+S, N-1); i++){
            if (A[i] > maximum.first) {
                maximum = {A[i], i};
            }
        }

        // left~maxi 스왑
        // 역순으로 하지 않으면 틀린다.
        for (int i=maximum.second; i>left; i--){
            swap(A[i], A[i-1]);
        }
        S -= maximum.second - left;

        left++;
    }

    for (int i=0; i<N; i++){
        cout << A[i] << ' ';
    }
    
    return 0;
}