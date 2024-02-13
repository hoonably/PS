#include <bits/stdc++.h>
using namespace std;

int N, ans = 1e9;
int S[20][20];
bool visited[20];

void backtracking(int idx, int depth){
    if (depth==N/2){
        int start = 0, rink = 0;
        for (int i=0; i<N; i++){
            for (int j=i+1; j<N; j++){
                if (visited[i] && visited[j]){
                    start += S[i][j] + S[j][i];
                }
                else if (!visited[i] && !visited[j]){
                    rink += S[i][j] + S[j][i];
                }
            }
        }
        if (abs(start-rink) < ans) {
            ans = abs(start-rink);
        }
    }

    // 마지막으로 추가한 idx+1 부터 탐색
    for (int i=idx+1; i<N; i++){
        if (visited[i]) continue;
        visited[i] = true;
        backtracking(i, depth+1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    backtracking(-1, 0);
    cout << ans;

    return 0;
}