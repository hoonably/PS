#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001

/*
x의 2^k(2의 k승)번째 조상을 parent[x][k]

합성함수 느낌으로

k=2, x의 4번째 조상으로 x의 두 번째 조상(parent[x][1])의 두 번째 조상이다.
parent[2][x] = parent[1][parent[1][x]]

2^k번째 조상
parent[x][k] = parent[k-1][parent[k-1][x]]

x의 13번째 조상 : {(x의 8번째 조상)의 4번째 조상}의 1번째 조상
*/

int MAXK = 16;  // N에 따른 최대 높이

int N, M, n1, n2; 
vector<int> graph[MAX]; 
bool visited[MAX]; 
int depth[MAX];
int parent[MAX][17];

void makeTree(int curr, int dep) { 
    visited[curr] = true ;
    depth[curr] = dep ;  

    for (int i = 0 ; i < graph[curr].size(); i++) {
        int next_node = graph[curr][i]; 
        if ( visited[next_node] ) continue; 
        parent[next_node][0] = curr ;
        makeTree(next_node, dep + 1); 
    }
}

int Fast_LCA(int x, int y) {
    if (depth[x] > depth[y]) swap(x,y); 

    for(int i = MAXK; i >= 0 ; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[y][i] ;
        }
    }

    if ( x == y ) return x; 

    for(int i = MAXK; i >= 0 ; i--) {
        if ( parent[x][i] != parent[y][i] ) {
            x = parent[x][i]; 
            y = parent[y][i]; 
        }
    }

    return parent[x][0] ;
}


int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N ; 

    for(int i = 0 ; i < N - 1; i++) {
        cin >> n1 >> n2; 
        graph[n1].push_back(n2); 
        graph[n2].push_back(n1); 
    }

    makeTree(1, 0) ;
    for (int i = 1 ; i <= MAXK; i++) {
        for (int j = 1;  j <= N ; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1]; 
        }
    }

    cin >> M ;  

    for(int i = 0 ; i < M ; i++) {
        cin >> n1 >> n2; 
        cout << Fast_LCA(n1, n2) << '\n'; 
    }

    return 0;
}