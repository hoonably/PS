#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1001

/*
자신의 막대기 3개중 하나만 제거할 수 있기 때문에,
a막대기를 제거하면 b와 c는 무조건 있어야 한다.
*/

#define x first
#define y second
using dot = pair<int, int>;

istream& operator >> (istream &in, dot &a){
    in >> a.x >> a.y;
    return in;
}
dot operator + (const dot &a, const dot &b){ return { a.x + b.x, a.y + b.y }; }
dot operator - (const dot &a, const dot &b){ return { a.x - b.x, a.y - b.y }; }
int operator * (const dot &a, const dot &b){ return a.x*a.x + a.y*a.y; }
int operator / (const dot &a, const dot &b){ return a.x*b.y - b.x*a.y; }
dot operator * (const dot &a, int b){ return { a.x * b, a.y * b }; }
dot operator / (const dot &a, int b){ return { a.x / b, a.y / b }; }

int N;
pair<dot, dot> line[3*MAX];

int id, sccSize;
int d[6*MAX];
bool finished[6*MAX];
int sccID[6*MAX];

vector<int> graph[6*MAX];
vector<vector<int>> SCC;
stack<int> s;

// 램프의 색을 출력하기 위한 배열
bool visited[6*MAX];
vector<int> deleteLine;

int ccw(const dot &p1, const dot &p2, const dot &p3){
    auto res = (p2 - p1) / (p3 - p2);
    return (res > 0) - (res < 0);
}

// 선분이 교차하는지
bool Cross(dot s1, dot e1, dot s2, dot e2){
    auto cw1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    auto cw2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if(cw1 == 0 && cw2 == 0){
        if(e1 < s1) swap(s1, e1);
        if(e2 < s2) swap(s2, e2);
        return !(e1 < s2 || e2 < s1);
    }
    return cw1 <= 0 && cw2 <= 0;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    // 막대기는 1,2,3 / 4,5,6, / ... 3*N
    for (int i=0; i<N; i++){
        int a = 3*i+1, b = 3*i+2, c = 3*i+3;
        cin >> line[a].first >> line[a].second;
        cin >> line[b].first >> line[b].second;
        cin >> line[c].first >> line[c].second;

        // 존재하는 막대기의 인덱스 : 원래 인덱스 2배
        // 없앤 막대기의 인덱스 : 원래 인덱스 2배 + 1
        a*=2; b*=2; c*=2;

        // a를 없앤 경우 => b, c 는 무조건 있음
        graph[a^1].push_back(b);
        graph[a^1].push_back(c);
        // b를 없앤 경우 => a, c 는 무조건 있음
        graph[b^1].push_back(a);
        graph[b^1].push_back(c);
        // c를 없앤 경우 => a, b 는 무조건 있음
        graph[c^1].push_back(a);
        graph[c^1].push_back(b);
    }

    // 막대기별로 겹치면 그래프 생성
    for (int i=1; i<=3*N; i++){
        for (int j=i+1; j<=3*N; j++){
            if (Cross(line[i].first, line[i].second, line[j].first, line[j].second)){
                int ti=i*2, tj=j*2;
                graph[ti].push_back(tj^1);  // i가 있다면 j는 없어야만 함
                graph[tj].push_back(ti^1);  // j가 있다면 i는 없어야만 함
            }
        }
    }

    // SCC 2~6N+1 (6N개)
    for(int i=2; i<=6*N+1; i++) {
        if(d[i]==0) dfs(i);
    }
    // Check
    for(int i=2; i<=6*N; i+=2) {
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
                visited[num] = true;
            }
            // num의 값이 홀수라면 지운거니까 답에 넣어줌
            else {
                if (visited[num^1]) continue;
                deleteLine.push_back(num/2);
                visited[num^1] = true;
            }
        }
    }
    cout << deleteLine.size() << '\n';
    sort(deleteLine.begin(), deleteLine.end());
    for(int i : deleteLine) {
        cout << i << ' ';
    }
    
    return 0;
}