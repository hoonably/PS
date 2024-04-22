#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX_N 1001

/*
상근이는 무조건 올라가야함
1 or 1 추가
not 1이면 1이다. 
를 추가함으로써 not 1이 나오면 절대 안되도록
*/

int N, M, K;
int id, sccSize;
int d[4*MAX_N];
bool finished[4*MAX_N];
int sccID[4*MAX_N];

vector<int> graph[4*MAX_N];
stack<int> s;

void init(){
    id = 0;
    sccSize = 0;
    memset(d, 0, sizeof(d));
    memset(finished, false, sizeof(finished));
    memset(sccID, 0, sizeof(sccID));
    for (int i=0; i<4*MAX_N; i++) graph[i].clear();
}

int dfs(int x){
    d[x] = ++id;  // 노드마다 고유 번호 할당
    s.push(x);

    int parent = d[x];  // 자신이 부모
    for (int child : graph[x]){
        // 방문 안한 노드
        if (d[child] == 0) parent = min(parent, dfs(child));
        // 방문은 했지만 처리가 안된 노드
        else if (!finished[child]) parent = min(parent, d[child]);
    }

    // 부모 노드가 자신인 경우 (사이클인 경우)
    if (parent == d[x]){
        while(true){
            int t = s.top();
            s.pop();
            sccID[t] = sccSize;  // 그룹 번호 저장
            finished[t] = true;
            if (t==x) break;
        }
        sccSize++;
    }
    return parent;  // 자신의 부모 값을 반환
}

bool solve(){

    // 가로 1~N, 세로 1~M
    cin >> N >> M >> K;

    int total = N+M;

    for (int i=0; i<K; i++){
        // 버스가 A번 가로 도로와 B번 세로 도로가 교차하는 마을에서, 
        // C번 가로 도로와 D번 세로 도로가 교차하는 마을로 이동함
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // 세로 도로는 가로 도로 + N 번으로 나타냄
        B += N, D += N;

        if (A==C && B==D) continue;

        // 가로가 같은 곳으로 간다면
        // 그 줄 가로는 방향 확정
        if (A==C){
            A*=2;
            // 세로로 내려감
            if (B<D) graph[A^1].emplace_back(A);
            // 세로로 올라감
            else graph[A].emplace_back(A^1);
            continue;
        }
        // 세로가 같은 곳으로 간다면
        // 그 줄 가로는 방향 확정
        if (B==D){
            B*=2;
            // 가로 오른쪽으로 감
            if (A<C) graph[B^1].emplace_back(B);
            // 가로 왼쪽으로 감
            else graph[B].emplace_back(B^1);
            continue;
        }
        
        A*=2; B*=2; C*=2; D*=2;
        if (A < C && B < D) {
            graph[B^1].emplace_back(A);
            graph[B^1].emplace_back(D);
            graph[C^1].emplace_back(A);
            graph[C^1].emplace_back(D);
            graph[A^1].emplace_back(B);
            graph[A^1].emplace_back(C);
            graph[D^1].emplace_back(B);
            graph[D^1].emplace_back(C);
        }
        else if (A < C && B > D) {
            graph[A].emplace_back(B);
            graph[A].emplace_back(C^1);
            graph[D^1].emplace_back(B);
            graph[D^1].emplace_back(C^1);
            graph[B^1].emplace_back(A^1);
            graph[B^1].emplace_back(D);
            graph[C].emplace_back(A^1);
            graph[C].emplace_back(D);
        }
        else if (A > C && B < D) {
            graph[B].emplace_back(A);
            graph[B].emplace_back(D^1);
            graph[C^1].emplace_back(A);
            graph[C^1].emplace_back(D^1);
            graph[A^1].emplace_back(B^1);
            graph[A^1].emplace_back(C);
            graph[D].emplace_back(B^1);
            graph[D].emplace_back(C);
        }
        else {
            graph[A].emplace_back(B^1);
            graph[A].emplace_back(C^1);
            graph[D].emplace_back(B^1);
            graph[D].emplace_back(C^1);
            graph[B].emplace_back(A^1);
            graph[B].emplace_back(D^1);
            graph[C].emplace_back(A^1);
            graph[C].emplace_back(D^1);
        }
    }

    // SCC
    for(int i=2; i<=2*total+1; i++) {
        if(d[i]==0) dfs(i);
    }

    // Check
    for(int i=2; i<=2*total; i+=2) {
        if(sccID[i] == sccID[i^1]) {  // 하나의 idx에 A와 !A가 모두 참 : 불가능하단 소리
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        init();
        if (solve()) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}