#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
< 플로이드 워셜 알고리즘 >
모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우
다익스트라에서 최단 거리 테이블에서 거리가 가장 짧은 노드를 탐색해야 했던 과정을 생략할 수 있다
시간복잡도 : O(N^3)
Dab = min(Dab, Dak + Dkb)
*/

#define INF 1e9

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int graph[n+1][n+1];
    fill(&graph[0][0], &graph[n+1][0], INF);  // INF로 모두 초기화
    
    // 자기 자신 거리 0 초기화
    for (int i=1; i<=n; i++){
        graph[i][i] = 0;
    }

    for (int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // 시작노드와 끝 노드가 같더라도 간선이 다를 경우 최저값 갱신
        graph[a][b] = min(graph[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF) cout << "0 ";
            else cout << graph[a][b] << ' ';
        }
        cout << '\n';
    }

    return 0;
}