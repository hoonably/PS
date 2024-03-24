#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
브루트포스가 가능
*/

double a[8];
double v[8];
bool visited[8];
int ans;

bool Check() {
	for (int i=0; i<8; i++){
		int a = i;
		int b = (i + 1) % 8;
		int c = (i + 2) % 8;
		if (v[a] * v[c] * sqrt(2) > v[b] * (v[a] + v[c])) {
			return false;
		}
	}
	return true;
}

// 모든 경우의 수 탐색
void dfs(int cnt) {
	if (cnt == 8) {
		ans += Check();
		return;
	}
	for (int i=0; i<8; i++){
		if (visited[i]) continue;
		visited[i] = 1;
		v[cnt] = a[i];
		dfs(cnt + 1);
		visited[i] = 0;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i=0; i<8; i++){
        cin >> a[i];
    }
    dfs(0);
    cout << ans;
    
    return 0;
}