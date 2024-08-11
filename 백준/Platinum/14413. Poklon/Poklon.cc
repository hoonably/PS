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
https://www.acmicpc.net/problem/8462

평행 분할(SQRT Decomposition) : 데이터가 N개이면 √N개만큼 나눠서 관리하는 방법

모스 알고리즘 : 어떤 구간 [s, e]에 속하는 원소들을 이용하여 어떤 값을 계산하는 쿼리를 처리하는 알고리즘
업데이트가 없어 쿼리의 순서를 변경해도 무방하기 때문에 쿼리 순서를 재배치하여 효율적으로 수행
배열을 k(√N)개로 이루어진 그룹으로 나눠주고, 아래 operator < 조건에 따라 먼저 처리한다.
*/

#define MAX 500'001

int sqrtN;
struct Query{
    int idx, s, e;
    bool operator < (const Query &A) const{
        // 1. [s1/k] < [s2/k] 라면 먼저 처리
        if(s/sqrtN != A.s/sqrtN) return s/sqrtN < A.s/sqrtN;
        // 2. [s1/k] = [s2/k] and e1 < e2 라면 먼저 처리
        return e < A.e;
    }
};

int N, Q;
vector<int> A, B;
int cnt[MAX];  // 좌표 압축 후 최대 500'000 가지
int res;
int ans[MAX];

void Plus(int x){
	if(cnt[x]==2) res--;
    if(++cnt[x]==2) res++;
}

void Minus(int x){
	if(cnt[x]==2) res--;
    if(--cnt[x]==2) res++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> Q;
    sqrtN = sqrt(N);
    A.resize(N+1);
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    // 좌표 압축
    B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for(int i=1; i<=N; i++) {
        A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }

    vector<Query> Qu(Q);
    for(int i=0; i<Q; ++i){
        cin >> Qu[i].s >> Qu[i].e;
        Qu[i].idx = i;
    }
    sort(all(Qu));  // 쿼리 정렬

    int s=0, e=0;

    // 이전 쿼리의 결과를 이용해 계산해나가기
    for(int i=0;i<Q;++i){
        while(s<Qu[i].s) Minus(A[s++]);
        while(s>Qu[i].s) Plus(A[--s]);
        while(e<Qu[i].e) Plus(A[++e]);
        while(e>Qu[i].e) Minus(A[e--]);
        ans[Qu[i].idx] = res;
    }

    for(int i=0; i<Q; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}