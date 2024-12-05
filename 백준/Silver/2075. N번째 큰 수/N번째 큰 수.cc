#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

int N;
int arr[1501][1501];

struct Node{
    int x, y, val;
    Node(int x, int y, int val): x(x), y(y), val(val) {}
    bool operator<(const Node &rhs) const {
        return val < rhs.val;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    priority_queue<Node, vector<Node>> pq;
    for(int i=1; i<=N; i++){
        pq.push(Node(N, i, arr[N][i]));
    }

    while(--N){
        Node cur = pq.top(); pq.pop();
        pq.push(Node(cur.x-1, cur.y, arr[cur.x-1][cur.y]));
    }
    cout << pq.top().val;
    
    return 0;
}