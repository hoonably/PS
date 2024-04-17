#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'001

/*
루트를 변경시키지 않고 
어떻게 루트를 r로 변경시킨 것과 같은 연산을 수행할 수 있는가?

주어진 노드가 세개이고, 각각의 LCA를 만드는 경우도 세가지가 있습니다.
X : 루트와 A노드의 LCA
Y : 루트와 B노드의 LCA
Z : A, B 노드의 LCA


세 노드간의 관계는 또 세가지가 있습니다.

1. A, B 모두 루트의 자식인 경우, Z가 답이 됩니다.
    1-1. Z는 깊이가 낮아도 루트의 깊이보다 낮지 않습니다.
    1-2. X, Y는 루트 노드가 됩니다.

2. A, B 중 하나만 자식인 경우, 루트가 답이 됩니다.
    2-1. A, B 노드 중 루트의 자식의 LCA는 루트 노드가 되며, 그렇지 않은 노드는 루트보다 부모 노드가 됩니다.
    2-1. Z는 1에서 루트의 자식이 아닌 노드와의 LCA 노드가 됩니다.

3. A, B 둘 다 루트의 자식이 아닌 경우, 루트와 두 노드의 LCA 중 루트에 가까운 노드가 답이 됩니다.(깊이가 깊은 노드)
    3-1. Z는 적어도 X, Y 중 깊이가 깊은 노드보다 깊이가 깊지 않습니다.

위 경우들을 종합해 볼 때, X, Y, Z 중 깊이가 가장 깊은 노드를 구하면 됩니다.
*/

int N, M;
int MAXK;  // N에 따른 최대 높이
int parent[17][MAX];  // 최대는 log2(100000) = 16.xx
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

    // 일단 1로 트리를 만들어줌
    makeTree(1, 1, 0);

    fillParent();

    cin >> M;
    for (int i=0; i<M; i++){
        int r, u, v;
        cin >> r >> u >> v;
        int x = lca(r,u);
        int y = lca(u,v);
        int z = lca(v,r);

        // 깊이가 가장 깊은노드 찾기
        int maxD = depth[x];
        int ans = x;
        if (depth[y]>maxD) {ans = y; maxD = depth[y];}
        if (depth[z]>maxD) ans = z;

        cout << ans << '\n';
    }
    
    return 0;
}