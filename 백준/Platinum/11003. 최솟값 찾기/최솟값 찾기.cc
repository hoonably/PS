#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, 
D에 저장된 수를 출력
*/

#define MAX 

int N, L;
deque<pii> dq;  // {인덱스, }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    for (int i=0; i<N; i++){
        int num;
        cin >> num;

        // 첫번째 인덱스가 지금꺼 -L이면 지움
        if (!dq.empty() && dq.front().first==i-L){
            dq.pop_front();
        }

        while(!dq.empty()){
            // 새로 넣는 것보다 큰게 있다면 모두 필요 없으니 삭제
            if (dq.back().second > num){
                dq.pop_back();
            }
            else break;
        }

        dq.push_back({i, num});
        
        cout << dq.front().second << ' ';
    }
    
    return 0;
}