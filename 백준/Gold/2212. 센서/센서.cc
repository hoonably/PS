#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 10001

/*
센서 사이의 거리가 큰 부분을 컷해야한다.

ex)
1 3 6 6 7 9 이고, 집중국이 2개라면

<1 3> <6 6 7 9> 로 나누어져야 하므로 
전체 거리의 합에서 가장 큰 거리인 3~6 거리를 빼준게 답이다.

ex)
1 3 6 6 7 9 이고, 집중국이 3개라면

<1 3> <6 6 7> <9> 로 나누어져야 하므로 
전체 거리의 합에서 가장 큰 거리인 3~6 거리와 7~9 거리를 빼준게 답이다.
*/

int N, K;
int sensor[MAX];
int dist[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> sensor[i];
    }
    sort(sensor, sensor+N);

    for (int i=0; i<N-1; i++){
        dist[i] = sensor[i+1]-sensor[i];
    }
    sort(dist, dist+N);

    int ans = 0;
    for (int i=0; i<N-(K-1); i++){
        ans += dist[i];
    }
    cout << ans;
    
    return 0;
}