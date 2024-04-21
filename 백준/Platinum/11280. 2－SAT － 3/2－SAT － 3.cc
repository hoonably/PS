#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX_N 10001

/*
SCC로 풀 수 있는 이유

함축 그래프 (implication graph) : 논리식의 변수들의 요구 조건을 나타낸 그래프

(A or B) 가 참이 되려면

A = false면 무조건 B = true 여야만 한다.
'p이면 q이다'의 필요조건과 충분조건 명제 활용해서 그래프를 만들 수 있다.
!A 이면 B이다. !B 이면 A이다.

각각 A, !A, B, !B, C, !C ... 들을 정점으로 나타내자.
그리고 (A^B)가 있다면 !A->B !B->A 를 그래프에 추가하자.
*/

// 인수가 idx
int N, M;
int id, sccSize;
int d[2*MAX_N];
bool finished[2*MAX_N];
int sccID[2*MAX_N];

vector<int> graph[2*MAX_N];
vector<vector<int>> SCC;
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

    // 절(clause)를 받으면서 그래프 생성
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        // 맞는 인덱스 : 원래 인덱스 두배 
        // Not 인덱스 : 원래 인덱스 두배 + 1
        if (a > 0) a *= 2;
        else a = -a * 2 + 1;

        if (b > 0) b *= 2;
        else b = -b * 2 + 1;

        graph[b ^ 1].push_back(a);  // not b 면 무조건 a
        graph[a ^ 1].push_back(b);  // not a 면 무조건 b
    }

    // SCC
    for(int i=2; i<=2*N+1; i++) {
        if(d[i]==0) dfs(i);
    }

    // Check
    for(int i=2; i<=2*N; i+=2) {
        if(sccID[i] == sccID[i+1]) {  // 하나의 idx에 A와 !A가 모두 참 : 불가능하단 소리
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';

    return 0;
}