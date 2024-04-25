#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'001

/*

*/

vector<int> segTree;

int init(int node, int s, int e) {
    if (s == e) return segTree[node] = 1;
    int mid = (s + e) / 2;
    return segTree[node] = init(node*2, s, mid) 
    + init(node*2 + 1, mid + 1, e);
}

// k번째 수 찾기
int find(int node, int s, int e, int k) {
	if (s == e) return s;
	int m = (s + e) / 2;
	if (k <= segTree[2 * node]) return find(2 * node, s, m, k);
	else return find(2 * node + 1, m + 1, e, k - segTree[2 * node]);
}

void deleting(int node, int s, int e, int target){
    if (target > e || target < s) return;
    segTree[node]--;
    if (s == e) return;
    int mid = (s + e) / 2;
    deleting(node*2, s, mid, target);
    deleting(node*2 + 1, mid + 1, e, target);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize, 1);

    init(1,1,N);

    int idx = 1;
    int remain = N;

    cout << "<";
    for (int i=0; i<N-1; i++){
        idx = (idx+K-1) % remain;
        if(idx==0) idx = remain;

        int num = find(1,1,N,idx);
        cout << num << ", ";
        deleting(1,1,N,num);
        
        remain--;
    }
    cout << find(1,1,N,1) << ">";
    

    return 0;
}