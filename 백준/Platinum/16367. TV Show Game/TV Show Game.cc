#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX_K 5001

/*
lamp 가 1~k 번호 매겨져있음
lamp 색은 red or blue, 켜지기 전까진 모름
3개가 랜덤으로 주어지면 그 3개가 무슨 색일지 맞추는거임
모든 램프가 켜지면 2~3개 맞은 사람은 상품을 타감

모든 사람이 상품을 타가도록 lamp 색을 조작

2-SAT 가 아닌거 같지만, 하나가 틀리면 나머지는 모두 맞아야 하므로
2-SAT가 맞다.
*/

int k, n;
int id, sccSize;
int d[2*MAX_K];
bool finished[2*MAX_K];
int sccID[2*MAX_K];

vector<int> graph[2*MAX_K];
vector<vector<int>> SCC;
stack<int> s;

// 램프의 색을 출력하기 위한 배열
bool visited[2*MAX_K];
char lamp[2*MAX_K];

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
        vector<int> scc;
        while(true){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            sccID[t] = sccSize;  // 그룹 번호 저장
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);
        sccSize++;
    }
    return parent;  // 자신의 부모 값을 반환
}

int getIdx(int num, char color){
    if (color == 'R') return 2*num;
    else return 2*num+1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> k >> n;
    for (int i=0; i<n; i++){
        int a, b,c;
        char ac, bc, cc;
        cin >> a >> ac >> b >> bc >> c >> cc;

        // R 인덱스 : 원래 인덱스 2배
        // B 인덱스 : 원래 인덱스 2배 + 1
        a = getIdx(a, ac);
        b = getIdx(b, bc);
        c = getIdx(c, cc);

        // a가 틀린 경우 => b, c 는 무조건 맞음
        graph[a^1].push_back(b);
        graph[a^1].push_back(c);
        // b가 틀린 경우 => a, c 는 무조건 맞음
        graph[b^1].push_back(a);
        graph[b^1].push_back(c);
        // c가 틀린 경우 => a, b 는 무조건 맞음
        graph[c^1].push_back(a);
        graph[c^1].push_back(b);
    }
    
    // SCC
    for(int i=2; i<=2*k+1; i++) {
        if(d[i]==0) dfs(i);
    }

    // Check
    for(int i=2; i<=2*k; i+=2) {
        if(sccID[i] == sccID[i^1]) {  // 하나의 idx에 A와 !A가 모두 참 : 불가능하단 소리
            cout << -1 << '\n';
            return 0;
        }
    }

    // 가능하면 변수들의 R, B 값을 저장하여 출력
    // 이때 visited 표시는 짝수에만 함
    for (vector<int> scc : SCC) {
        for (int num : scc) {
            // num의 값이 짝수(R)라면 그에 해당하는 순서의 변수를 R로
            if (num%2==0) {
                if (visited[num]) continue;
                lamp[num] = 'R';
                visited[num] = true;
            }
            // num의 값이 홀수(B)라면 그에 해당하는 순서의 변수를 B로 
            else {
                if (visited[num^1]) continue;
                lamp[num^1] = 'B';
                visited[num^1] = true;
            }
        }
    }
    for(int i=2; i<=2*k; i+=2) {
        cout << lamp[i];
    }

    return 0;
}