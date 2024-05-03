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

*/

#define MAX 1001

int N;
pii HW[MAX];  // {마감일, 점수}
int cost[MAX];  // cost[마감일] = 점수

bool cmp(pii a, pii b){
    return a.second > b.second;
}  // 점수가 높은 순으로 정렬

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    FOR(i,0,N){
        cin >> HW[i].first >> HW[i].second;
    }

    sort(HW, HW+N);
    for (int i=0; i<N; i++){
        auto [day,score] = HW[i];

        pii mini = {0,1e9};  // 점수가 가장 낮은 날, 점수
        while(day>0){
            if (cost[day]==0) {
                cost[day] = score;
                break;
            }
            if (cost[day]<mini.second){
                mini = {day, cost[day]};
            }
            day--;
        }

        // 점수 갱신
        if(day==0 && mini.second < score){
            cost[mini.first] = score;
        }
    }

    int ans = 0;
    for (int i=1; i<MAX; i++){
        // cout << cost[i] << ' ';
        ans += cost[i];
    }
    cout << ans;
    
    return 0;
}