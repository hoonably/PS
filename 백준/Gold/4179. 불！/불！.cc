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

int R,C;
char board[1001][1001];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dist1[1001][1001]; //불의 전파 시간
int dist2[1001][1001]; // 탈출 속도



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

	queue<pair<int, int>> Q1; //불
	queue<pair<int, int>> Q2; //탈출

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < R; i++) {
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty()) {
		auto [x,y] = Q1.front(); Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[x][y] + 1;
			Q1.push({ nx,ny });

		}
	}


	while (!Q2.empty()) {
		auto [x,y] = Q2.front(); Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << dist2[x][y] + 1;
				return 0;  // find
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1) continue;

			dist2[nx][ny] = dist2[x][y] + 1;
			Q2.push({ nx,ny });

		
 		}
	}
	cout << "IMPOSSIBLE";
    
    return 0;
}