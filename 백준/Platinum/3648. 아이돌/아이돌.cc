#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX_N 1001

/*
무조건 상근이는 올라가야 하므로 -1이 있다면 뒤에는 무조건 맞아야한다.


*/

int n, m;
int id, sccSize;
int d[2*MAX_N];
bool finished[2*MAX_N];
int sccID[2*MAX_N];

vector<int> graph[2*MAX_N];
stack<int> s;

void init(){
    id = 0;
    sccSize = 0;
    memset(d, 0, sizeof(d));
    memset(finished, false, sizeof(finished));
    memset(sccID, 0, sizeof(sccID));
    for (int i=0; i<2*MAX_N; i++) graph[i].clear();
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

    // 상근이는 무조건 올라가야함
    // 1 or 1 추가 (1이 아니면 1이여야함)
    graph[2^1].push_back(2);

    // 절(clause)를 받으면서 그래프 생성
    for(int i=0; i<m; i++) {
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
    for(int i=2; i<=2*n+1; i++) {
        if(d[i]==0) dfs(i);
    }

    // Check
    for(int i=2; i<=2*n; i+=2) {
        if(sccID[i] == sccID[i^1]) {  // 하나의 idx에 A와 !A가 모두 참 : 불가능하단 소리
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(cin>>n>>m){  // eof
        init();
        if (solve()) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}