#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001

/*
2-SAT 으로 풀 수 있는 이유
모든 방은 두 개의 스위치와 연결되어 있다.

두개의 스위치만 생각하면 되므로
A or B 로 2-SAT 으로 풀면 된다.
*/

// 인수가 idx
int N, M;
bool room[MAX];
vector<int> swich[MAX];

int id, sccSize;
int d[2*MAX];
bool finished[2*MAX];
int sccID[2*MAX];

vector<int> graph[2*MAX];
stack<int> s;

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    // 방 초기 상태 받기
    for (int i=1; i<=N; i++){
        cin >> room[i];
    }

    // 방 번호에 대한 스위치 번호 넣기
    for(int i=0; i<M; i++) {
        int K;
        cin >> K;
        for (int j=0; j<K; j++){
            int num;
            cin >> num;
            swich[num].push_back(i);
        }
    }

    // graph 생성
    for (int i=1; i<=N; i++){
        int a = swich[i][0]*2;
        int b = swich[i][1]*2;
        // 이미 불이 켜져있다면 연결된 스위치를 둘다 키거나 둘다 꺼야함
        // not A -> not B, A -> B
        if (room[i]){
            graph[a^1].push_back(b^1);
            graph[a].push_back(b);
            graph[b^1].push_back(a^1);
            graph[b].push_back(a);
        }
        // 불이 꺼져있다면 연결된 스위치 중 하나만 켜져야함
        // not A -> B, A -> not B
        else {
            graph[a^1].push_back(b);
            graph[a].push_back(b^1);
            graph[b^1].push_back(a);
            graph[b].push_back(a^1);
        }
    }

    // SCC
    for(int i=2; i<=2*N+1; i++) {
        if(d[i]==0) dfs(i);
    }

    // Check
    for(int i=2; i<=2*N; i+=2) {
        if(sccID[i] == sccID[i^1]) {  // 하나의 idx에 A와 !A가 모두 참 : 불가능하단 소리
            cout << "0";
            return 0;
        }
    }
    cout << "1";

    return 0;
}