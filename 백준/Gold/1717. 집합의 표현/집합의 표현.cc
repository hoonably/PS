#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

/*
union find
= parent 초기화를 꼭 해주자.
*/

int n, m;
int parent[MAX];

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    // parent 초기화
    for (int i=1; i<=n; i++){
        parent[i]=i;
    }

    for (int i=0; i<m; i++){
        int order, a, b;
        cin >> order >> a >> b;
        if (order==0) {  // order = 0일 경우 두 집합 합침
            unionParent(a, b);
        }
        else {  // order !=0 일 경우 a와 b가 같은 집합이면 YES 출력
            if (findParent(a)==findParent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}