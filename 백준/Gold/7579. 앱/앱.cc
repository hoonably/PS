#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
어려운 냅색 알고리즘
# dp[i] = k
# i만큼의 비용이 들었을때 최대로 줄일 수 있는 메모리량
*/

int N, M;
int m[101], c[101], dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> m[i];
    }

    int total=0;  // total cost

    for(int i=0; i<N; i++){
        cin >> c[i];
        total+=c[i];
    }

    for (int i = 0; i < N; i++) {
		for (int j = total; j >= c[i]; j--) {
            // i번째 앱 안지웠을때 메모리 vs i번째 앱을 지웠을때 메모리
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
		}
	}

    // M 바이트 이상을 확보하는 최소의 비용 출력 후 종료
	for (int i = 0; i <= total; i++) {
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}
    
    return 0;
}