#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

unordered_set<int> S;

int bfs(int s){
    queue<int> q;
    q.push(s);
    S.insert(s);
    int cnt = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int cur = q.front(); q.pop();
            if(cur == 123456780) return cnt;
            string str = to_string(cur);
            int idx = str.find('0');
            // 0이 맨 처음이라 없어진 경우
            if(idx == -1) {
                idx = 0;
                str = "0" + str;
            }
            int x = idx/3, y = idx%3;
            int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0 || nx>=3 || ny<0 || ny>=3) continue;
                string next = str;
                swap(next[x*3+y], next[nx*3+ny]);
                int nextInt = stoi(next);
                if(S.find(nextInt) != S.end()) continue;
                S.insert(nextInt);
                q.push(nextInt);
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int start = 0;
    for(int i=0; i<9; i++){
        int a; cin >> a;
        start = start*10 + a;
    }
    cout << bfs(start);
    
    return 0;
}