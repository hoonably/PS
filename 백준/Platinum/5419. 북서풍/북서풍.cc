#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 75000

/*
y는 감소, x는 증가하는 방향으로만 항해할 수 있음
섬 두개만 방문하는 그 쌍의 개수를 구하는거임
한번에 3개 이상 섬 방문 X

메모리 터지기 전에 y축 좌표 압축 진행

x축 기준으로 오름차순, y축 기준으로 내림차순으로 정렬한 뒤 
서대로 업데이트하면서 쿼리
*/

int N;
vector<int> segTree;  // 
vector<int> y_compress;  // y좌표 압축

bool compare(pii &v1, pii &v2){
    if(v1.first == v2.first) return v1.second > v2.second;
    else return v1.first < v2.first;
}

void update(int node, int s, int e, int target){
    if (target > e || target < s) return;
    segTree[node] ++;
    if (s == e) return;
    int m = (s + e) / 2;
    update(node*2, s, m, target);
    update(node*2 + 1, m + 1, e, target);
}

// 
int sum(int node, int s, int e, int left, int right){
    if (left > e || right < s)
        return 0;
    if (left <= s && right >= e)
        return segTree[node];
    int m = (s + e) / 2;
    return sum(node*2, s, m, left, right) 
    + sum(node*2+1, m+1, e, left, right);
}

// 이분탐색을 이용해 압축된 좌표의 인덱스 찾기
int findIdx(int val){
    return lower_bound(y_compress.begin(), y_compress.end(), val) - y_compress.begin();
}

void solve(){

    cin >> N;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree = vector<int>(treeSize);

    vector<pii> v;
    y_compress.clear();

    for (int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        y_compress.push_back(b);
    }

    sort(v.begin(), v.end(), compare);
    sort(y_compress.begin(), y_compress.end());
    y_compress.erase(unique(y_compress.begin(), y_compress.end()), y_compress.end());  // 중복 제거

    ll ans = 0;
    for(int i = 0; i < N; i++){

        // 좌표압축 인덱스 구하기
        int yIdx = findIdx(v[i].second);

        // 좌표압축된 인덱스 ~ 마지막 까지의 합 구하기
        ans += sum(1, 0, N-1, yIdx, N-1);
        update(1, 0, N-1, yIdx);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}