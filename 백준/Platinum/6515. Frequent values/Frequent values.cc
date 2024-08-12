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
https://www.acmicpc.net/problem/6515

평행 분할 + 모스 알고리즘
*/

#define MAX 100001

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
int A[MAX];
int cnt[2*MAX];
int table[MAX];  // table[y] = (cnt[x] == y)를 만족하는 y의 개수
int res;  // 모든 cnt[x] 중 최댓값
int ans[MAX];

void Plus(int x){
	if(cnt[x] != 0) table[cnt[x]]--;
	cnt[x]++; 
    table[cnt[x]]++;
	res = max(res, cnt[x]);  // result 갱신
}

void Minus(int x){
	table[cnt[x]]--;
	if(cnt[x] == res && !table[cnt[x]]) res--;
	cnt[x]--;
	table[cnt[x]]++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(true){

        memset(cnt, 0, sizeof(cnt));
        memset(table, 0, sizeof(table));
        res = 0;

        cin >> N;
        if (N==0) return 0;  // TC 종료
        cin >> Q;

        sqrtN = sqrt(N);
        for (int i = 1; i <= N; ++i){
            int num;
            cin >> num;
            A[i] = num + MAX;  // 음수도 들어오므로
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
    }

    
    return 0;
}