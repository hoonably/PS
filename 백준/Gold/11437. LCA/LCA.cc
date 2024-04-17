#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 50'001

/*
x의 2^k(2의 k승)번째 조상을 parent[x][k]

합성함수 느낌으로

k=2, x의 4번째 조상으로 x의 두 번째 조상(parent[x][1])의 두 번째 조상이다.
parent[2][x] = parent[1][parent[1][x]]

2^k번째 조상
parent[x][k] = parent[k-1][parent[k-1][x]]

x의 13번째 조상 : {(x의 8번째 조상)의 4번째 조상}의 1번째 조상
*/

int N, M;
int MAXK;  // N에 따른 최대 높이
int parent[16][MAX];  // 최대는 log2(100000) = 16.xx
int depth[MAX];
vector<int> v[MAX];

// 트리를 만들면서 각각의 parent와 depth 구하기
void makeTree(int par, int now, int dep){

    parent[0][now] = par;   // 부모 노드 기록 [ 2^0 (1)번째 조상 ]
    depth[now] = dep;  // 현재 노드의 깊이 기록

    for(int son : v[now]){
        // 부모가 아니라면 자식일 수 밖에 없으므로 재귀
        if(son != par) makeTree(now, son, dep+1);
    }
}

// 부모 배열 채워줌
void fillParent() {  
    for (int k = 1; k <= MAXK; k++)
        for (int i = 1; i <= N; i++)
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int dif = depth[a] - depth[b];

    // a와 b의 높이차를 없애주기 위해
    // a를 높이차 만큼의 부모로 변경
    for(int i=0; dif>0 ; ++i){
        if(dif%2==1) a = parent[i][a];
        dif >>= 1;
    }
 
    if (a == b) return a;

    for (int k = MAXK; k >= 0; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    // 이러면 a와 b의 바로 위의 부모가 같아짐

    return parent[0][a];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    MAXK = log2(N);

    for (int i=0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    // 1을 root로 잡고 트리 생성
    makeTree(1, 1, 0);
    fillParent();

    cin >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}