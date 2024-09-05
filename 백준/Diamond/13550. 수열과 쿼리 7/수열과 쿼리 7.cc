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
https://www.acmicpc.net/problem/13546

1과 -1로만 이루어져 있는 길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

i j: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 합을 K로 나눈 값이 0이면서 가장 긴 연속하는 부분 수열의 길이를 출력한다.

Ai ~ Aj의 합 = A1~Aj 합 - A1~Ai의 합 (누적합 사용)

배열의 인덱스가 음수가 될 수 있기 때문에 모두 100'000을 더해준다.
*/

#define MAXN 100'001

const int sqrtN = 330;
const int SZ = MAXN/sqrtN + 10;  // 분할 후 개수

struct Query{
    int idx, s, e;
    bool operator < (const Query &S) const{
        int block1 = s/sqrtN, block2 = S.s/sqrtN;
        // 1. 분할값이 다르다면
        if(block1 != block2) return block1 < block2;
        // 2. 분할값이 같다면 e1 < e2 라면 먼저 처리
        return e < S.e;
    }
};

int N, M, K;
int S[MAXN];
int cnt[1000001], bucket[1001];
int ans[MAXN];
list<int> pos[1000001];  // list가 deque보다 빠르고 메모리 덜 사용


void Plus(int x, bool changeFront){
	int dist = 0;
	auto &dq = pos[S[x]];
	if(!dq.empty()){
		dist = dq.back() - dq.front();
		cnt[dist]--;
		bucket[dist/sqrtN]--;
	}
	if(changeFront) dq.emplace_front(x);  // 앞을 변경
	else dq.emplace_back(x);  // 뒤를 변경

	dist = dq.back() - dq.front();
	cnt[dist]++; 
    bucket[dist/sqrtN]++;
}

void Minus(int x, bool changeFront){
	auto &dq = pos[S[x]];
	int dist = dq.back() - dq.front();
    cnt[dist]--;
    bucket[dist/sqrtN]--;

	if(changeFront) dq.pop_front();  // 앞을 변경
	else dq.pop_back();  // 뒤를 변경

	if(!dq.empty()){
		dist = dq.back() - dq.front();
		cnt[dist]++; 
        bucket[dist/sqrtN]++;
	}
}

int query(){
    // 제일 뒤의 버킷부터 체크
	for(int i=SZ-1; i>=0; i--){
		if(bucket[i] == 0) continue;
        // 제일 뒤의 값부터 있다면 그 값 return
        int idx = (i + 1) * sqrtN;
        while(--idx){
            if (cnt[idx] != 0) {
                return idx;
            }
        }
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    // 누적합
    for (int i = 1; i <= N; ++i){
        cin >> S[i];
        S[i] = (S[i] + S[i-1]) % K;
    }

    cin >> M;
    vector<Query> Qu;
    for(int i=0; i<M; ++i){
        int s, e;
        cin >> s >> e;
        // S[e]-S[s-1] : s~e 누적합
        Qu.push_back({i, s-1, e});
    }
    sort(all(Qu));  // 쿼리 정렬

    // 이전 쿼리의 결과를 이용해 계산해나가기

   // 먼저 이렇게 안하고 0부터 while문 돌렸다가 Minus에서 deque가 비어있어서 틀렸음
	int s = Qu[0].s, e = Qu[0].e;
	for(int i=s; i<=e; i++){
		Plus(i, false);  // while(e<Qu[i].e) Plus(++e, false); 와 같은 작업
	}
	ans[Qu[0].idx] = query();

    for(int i=1;i<M;++i){
        // 순서 중요
        // 먼저 pop해버리면 안됨
        while(e<Qu[i].e) Plus(++e, false);
        while(e>Qu[i].e) Minus(e--, false);
        while(s>Qu[i].s) Plus(--s, true);
        while(s<Qu[i].s) Minus(s++, true);
        ans[Qu[i].idx] = query();
    }

    for(int i=0; i<M; ++i) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}