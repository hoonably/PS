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
string name;
map<string,int> carIdx;
int before[1000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        
        cin >> name;
        carIdx[name] = i;
    }

    
    for (int nowIdx=0; nowIdx<N; nowIdx++){
        cin >> name;
        before[nowIdx] = carIdx[name];
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        // 자기보다 빨랐던게 뒤에 하나라도 있다면 추월한거임
        for(int j=i+1; j<N; j++){
            if(before[j]<before[i]){
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
    
    return 0;
}