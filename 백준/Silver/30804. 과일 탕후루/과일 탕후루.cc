#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/30804

*/

#define MAX 200'000

int N, types;
int cnt[10];
queue<int> q;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    while (N--) {
        int fruit;
        cin >> fruit;

        q.push(fruit);

        if (cnt[fruit]++ == 0) ++types;

        // 종류가 2개 이상이라면 먼저 넣었던거부터 계속 뺌
        while (types > 2) {
            fruit = q.front();
            q.pop();

            if (--cnt[fruit] == 0) --types;
        }

        ans = max(ans, (int)q.size());
    }

    cout << ans;

    return 0;
}