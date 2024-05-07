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

#define MAX 51

int N;
int num[MAX];
bool visited[MAX];
int match[MAX];
bool isPrime[2001];  // 소수인지

vector<int> primes;

void eratos(int n) {  // 0 ~ N까지 isPrime 생성
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int meet1;// dfs에서 제외할 1과 연결된 값

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int i=2; i<=N; i++){
        
        // 1과 연결된 값이면 넘김
        if(i == meet1) continue;

        // 합이 소수가 아니면 넘김
        if(!isPrime[num[cur]+num[i]]) continue;

        // 아직 매칭되지 않았면 그 일 매칭
        // dfs 결과 그 사람이 다른곳으로 배정이 되었다면 매칭완료
		if (match[i] == 0 || dfs(match[i])) {
			match[i] = cur;
			return true;
		}
    }
    return false;
}

bool bipartite_match() {
    for (int i=2; i<=N; i++) {
        if (i==meet1) continue;
        memset(visited, 0, sizeof(visited));
        if (!dfs(i)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    eratos(2000);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> num[i];
    }

    vector<int> ans;
    for (int i=2; i<=N; i++){
        if(!isPrime[num[1]+num[i]]) continue;
        memset(match, 0, sizeof(match));
        meet1 = i;
        if (bipartite_match()) ans.push_back(num[i]);
    }

    if (ans.empty()) cout << "-1";
    else{
        sort(all(ans));
        for (int i : ans){
            cout << i << ' ';
        }
    }
    return 0;
}