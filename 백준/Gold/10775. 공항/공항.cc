#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
3 -> 1~3 번 중 아무곳이나 넣어도 됨

223344라면

123 에 차례로 넣고
4번째가 1~3에 넣어야 하는데 못 넣음

분리집합을 사용하지 않고 하나씩 줄이면 O(N^2)
*/

int G, P;
int parent[100001];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    // 작은 값으로 union
    if (a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> G >> P;

    for (int i=1; i<=G; i++){
        parent[i] = i;
    }

    int ans = 0;
    for (int i=0; i<P; i++){
        int num;
        cin >> num;

        num = findParent(num);

        // 부모가 0이라면 넣을 수 없는거임
        if (num==0) break;

        unionParent(num, num-1);

        ans++;
    }
    cout << ans;
    
    return 0;
}