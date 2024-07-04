#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX

int N;
int a, b;
int lastMin, lastSec;
pii Atime, Btime;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {

        int team;
        cin >> team;

        string time;
        cin >> time;

        int nowMin = (time[0] - '0') * 10 + time[1] - '0';
        int nowSec = (time[3] - '0') * 10 + time[4] - '0';

        // 1팀이 이기고 있었던 경우
        if (a>b){
            Atime.first += nowMin - lastMin;
            Atime.second += nowSec - lastSec;
        }
        // 2팀이 이기고 있었던 경우
        else if (a<b){
            Btime.first += nowMin - lastMin;
            Btime.second += nowSec - lastSec;
        }

        // 현재 시각변경
        lastMin = nowMin;
        lastSec = nowSec;

        if (team==1) a++;
        else b++;
    }

    // 1팀이 이기고 있었던 경우
    if (a>b){
        Atime.first += 48 - lastMin;
        Atime.second += - lastSec;
    }
    // 2팀이 이기고 있었던 경우
    else if (a<b){
        Btime.first += 48 - lastMin;
        Btime.second += - lastSec;
    }

    // 분 음수처리
    while(Atime.second < 0){
         Atime.first--;
         Atime.second+=60;
    }
    while(Btime.second < 0){
         Btime.first--;
         Btime.second+=60;
    }
    // 분 60이상 처리
    while(Atime.second >= 60){
         Atime.first++;
         Atime.second-=60;
    }
    while(Btime.second >= 60){
         Btime.first++;
         Btime.second-=60;
    }

    if (Atime.first<10) cout << '0';
    cout << Atime.first << ':';
    if (Atime.second<10) cout << '0';
    cout << Atime.second << '\n';

    if (Btime.first<10) cout << '0';
    cout << Btime.first << ':';
    if (Btime.second<10) cout << '0';
    cout << Btime.second << '\n';
    

    return 0;
}