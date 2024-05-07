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
하루에 한개의 과제를 할 수 있을때, 
마감일과 점수가 주어진다.
점수를 최대로 얻으려고 하면 몇까지 얻을 수 있는가?
*/

#define MAX 10001

int N;
pii HW[MAX];  // {마감일, 점수}
int cost[MAX];  // cost[마감일] = 점수

bool cmp(pii a, pii b){
    return a.second < b.second;
}  // 기간이 짧은 순서로 정렬

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    FOR(i,0,N){
        // 강연료, 기간 받기
        cin >> HW[i].first >> HW[i].second;
    }

    sort(HW, HW+N, cmp);
    for (int i=0; i<N; i++){
        auto [money, day] = HW[i];

        pii mini = {0,1e9};  // 점수가 가장 낮은 날, 점수
        while(day>0){
            // 비어있는 날이 있다면
            if (cost[day]==0) {
                cost[day] = money;
                break;
            }
            // 점수 가장 낮은 날, 그때 점수 저장
            if (cost[day]<mini.second){
                mini = {day, cost[day]};
            }
            day--;
        }

        // 빈 자리가 없고, 최솟값보다 크다면 그 자리에 갱신
        if(day==0 && mini.second < money){
            cost[mini.first] = money;
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