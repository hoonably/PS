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
https://www.acmicpc.net/problem/13547

평행 분할(SQRT Decomposition) : 데이터가 N개이면 √N개만큼 나눠서 관리하는 방법

모스 알고리즘은 어떤 구간 [s, e]에 속하는 원소들을 이용하여 어떤 값을 계산하는 쿼리를 처리하는 알고리즘이다.

업데이트가 없어 쿼리의 순서를 변경해도 무방하기 때문에 쿼리 순서를 재배치하여 효율적으로 수행

배열을 k(√N)개로 이루어진 그룹으로 나눠주고, 쿼리를 실행할 때 두 조건 중 하나를 만족하는 경우 먼저 처리한다.
[s1/k] < [s2/k]
[s1/k] = [s2/k] and e1 < e2
*/

#define MAX 1'000'001

int sqrtN;
struct Query{
    // i j: Ai ~ Aj에 존재하는 서로 다른 수의 개수
    int idx, s, e;
    bool operator < (const Query &A) const{
        if(s/sqrtN != A.s/sqrtN) return s/sqrtN < A.s/sqrtN;
        return e < A.e;
    }
};

int N, Q;
vector<int> A, B;
// 좌표압축하지 않으면 cnt[10억] 이 되므로 불가능
int cnt[MAX];  // 좌표 압축 후 최대 1'000'000 까지
int res;
int ans[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
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

    cin >> Q;
    vector<Query> Qu(Q);
    for(int i=0; i<Q; ++i){
        cin >> Qu[i].s >> Qu[i].e;
        Qu[i].idx = i;
    }
    sort(all(Qu));  // 쿼리 정렬

    int s=0, e=0;

    // 이전 쿼리의 결과를 이용해 계산해나가기
    for(int i=0;i<Q;++i){
        while(s<Qu[i].s) if (--cnt[A[s++]]==0) --res;
        while(s>Qu[i].s) if (++cnt[A[--s]]==1) ++res;
        while(e>Qu[i].e) if (--cnt[A[e--]]==0) --res;
        while(e<Qu[i].e) if (++cnt[A[++e]]==1) ++res;
        ans[Qu[i].idx]=res;
    }

    for(int i=0; i<Q; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}