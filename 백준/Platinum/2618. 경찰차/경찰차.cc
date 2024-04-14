#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

/*
dp[i][i] 
경찰차 1이 마지막으로 i번째 사건 해결,
경찰차 2가 마지막으로 j번째 사건 해결했을 경우
총 거리의 합의 최소값 저장
*/

int N, M;
pii accident[1001], before[1001][1001];
int dp[1001][1001];

int dist(int car, int start, int end){
    
    if (start==0){
        if (car==1){
            return accident[end].first-1 + accident[end].second-1;
        }
        else {
            return N-accident[end].first + N-accident[end].second;
        }
    }

    // c++17 부터 가능 auto unpacking
    auto [x1, y1] = accident[start];
    auto [x2, y2] = accident[end];

    return abs(x1-x2)+abs(y1-y2);
}

void backtrace (int x, int y) {
	if (x==0 && y==0) return;
	int nx = before[x][y].first;
    int ny = before[x][y].second;
    backtrace(nx, ny);
	if (x>y) cout << "1\n";
    else cout << "2\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        cin >> accident[i].first >> accident[i].second;
    }


    // dp 초기화
    for(int i=0; i<=M; i++){
        for (int j=0; j<=M; j++){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0]=0;

    // 처음에 시작점에서 이동하는 경우만 따로 해줘야함

    for (int end=1; end<=M; end++){

        // end-1을 경찰차1이 방문한 경우
        for (int car2=0; car2<=end-1; car2++){

            // end를 경찰차1이 또 방문
            int dist11 = dp[end-1][car2] + dist(1, end-1, end);
            if (dist11<dp[end][car2]){
                dp[end][car2] = dist11;
                before[end][car2] = {end-1, car2};
            }

            // end를 경찰차2가 방문
            int dist12 = dp[end-1][car2] + dist(2, car2, end);
            if(dist12 < dp[end-1][end]){
                dp[end-1][end] = dist12;
                before[end-1][end] = {end-1, car2};
            }
        }


        // end-1을 경찰차2이 방문한 경우
        for (int car1=0; car1<=end-1; car1++){
            // end를 경찰차2가 또 방문
            int dist22 = dp[car1][end-1] + dist(2, end-1, end);
            if(dist22<dp[car1][end]){
                dp[car1][end] = dist22;
                before[car1][end] = {car1, end-1};
            }

            // end를 경찰차1이 방문
            int dist21 = dp[car1][end-1] + dist(1, car1, end);
            if(dist21 < dp[end][end-1]){
                dp[end][end-1] = dist21;
                before[end][end-1] = {car1, end-1};
            }
        }
    }


    // 최대값 찾기
    int ans = 1e9;
    pii idx;
    for(int i=0; i<M; i++){
        if (dp[M][i] < ans){
            ans = dp[M][i];
            idx = {M,i};
        }
        if (dp[i][M] < ans){
            ans = dp[i][M];
            idx = {i,M};
        }
    }
    cout << ans << '\n';
    backtrace(idx.first, idx.second);

    return 0;
}