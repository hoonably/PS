#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/13548

평행 분할(SQRT Decomposition) : 데이터가 N개이면 √N개만큼 나눠서 관리하는 방법

모스 알고리즘은 어떤 구간 [s, e]에 속하는 원소들을 이용하여 어떤 값을 계산하는 쿼리를 처리하는 알고리즘이다.

업데이트가 없어 쿼리의 순서를 변경해도 무방하기 때문에 쿼리 순서를 재배치하여 효율적으로 수행

배열을 k(√N)개로 이루어진 그룹으로 나눠주고, 쿼리를 실행할 때 두 조건 중 하나를 만족하는 경우 먼저 처리한다.
[s1/k] < [s2/k]
[s1/k] = [s2/k] and e1 < e2
*/

#define MAX 100001

int sqrtN;
struct Query{
    // i j: Ai ~ Aj에 존재하는 서로 다른 수의 개수
    int idx, s, e;
    bool operator < (const Query &A) const{
        if(s/sqrtN != A.s/sqrtN) return s/sqrtN < A.s/sqrtN;
        return e < A.e;
    }
};

int N, M;
int A[MAX];
int cnt[1000001];
int table[MAX];  // table[y] = (cnt[x] == y)를 만족하는 y의 개수
int res;  // 모든 cnt[x] 중 최댓값
int ans[MAX];

void Plus(int x){
	if(cnt[x] != 0) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void Minus(int x){
	table[cnt[x]]--;
	if(cnt[x] == res && !table[cnt[x]]) res--;
	cnt[x]--;
	table[cnt[x]]++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    sqrtN = sqrt(N);
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    cin >> M;
    vector<Query> Q(M);
    for(int i=0; i<M; ++i){
        cin >> Q[i].s >> Q[i].e;
        Q[i].idx = i;
    }
    sort(all(Q));  // 쿼리 정렬

    int s=0, e=0;

    // 이전 쿼리의 결과를 이용해 계산해나가기
    for(int i=0;i<M;++i){
        while(s<Q[i].s) Minus(A[s++]);
        while(s>Q[i].s) Plus(A[--s]);
        while(e<Q[i].e) Plus(A[++e]);
        while(e>Q[i].e) Minus(A[e--]);
        ans[Q[i].idx] = res;
    }

    for(int i=0; i<M; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}