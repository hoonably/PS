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

1~K로 이루어진 수열 A1~AN
l r 이 주어졌을 때 l <= x, y <= r 이면서 Ax=Ay인 y-x의 최대값 출력

기존 |back - front|를 prv, 삽입/삭제 연산으로 인해 새로 바뀐 |back - front|를 now라고 합시다.
prv가 등장한 횟수가 1 감소하고, now가 등장한 횟수가 1 증가합니다.
*/

#define MAX 100'001

const int sqrtN = 300;
const int SZ = MAX/sqrtN;  // 분할 후 개수

struct Query{
    int idx, s, e;
    bool operator < (const Query &A) const{
        // 1. 분할값이 다르다면
        if(s/sqrtN != A.s/sqrtN) return s < A.s;
        // 2. 분할값이 같다면 e1 < e2 라면 먼저 처리
        return e < A.e;
    }
};

int N, M, K;
int A[MAX];
int cnt[MAX], bucket[SZ];
int ans[MAX];
deque<int> pos[MAX];


void Plus(int x, bool changeFront){
	int now = 0;
	auto &dq = pos[A[x]];
	if(!dq.empty()){
		now = dq.back() - dq.front();
		cnt[now]--;
		bucket[now/sqrtN]--;
	}
	if(changeFront) dq.push_front(x);  // 앞을 변경
	else dq.push_back(x);  // 뒤를 변경

	now = dq.back() - dq.front();
	cnt[now]++; bucket[now/sqrtN]++;
}

void Minus(int x, bool changeFront){
	auto &dq = pos[A[x]];
	int now = dq.back() - dq.front();
    cnt[now]--;
    bucket[now/sqrtN]--;

	if(changeFront) dq.pop_front();  // 앞을 변경
	else dq.pop_back();  // 뒤를 변경

	if(!dq.empty()){
		now = dq.back() - dq.front();
		cnt[now]++; 
        bucket[now/sqrtN]++;
	}
}

int query(){
    // 제일 뒤의 버킷부터 체크
	for(int i=SZ-1; i>=0; i--){
		if(bucket[i] == 0) continue;
        // 제일 뒤의 값부터 있다면 그 값 return
		for(int j=sqrtN-1; j>=0; j--){
			if(cnt[i*sqrtN+j] > 0){
				return i*sqrtN+j;
			}
		}
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    cin >> M;
    vector<Query> Qu(M);
    for(int i=0; i<M; ++i){
        cin >> Qu[i].s >> Qu[i].e;
        Qu[i].idx = i;
    }
    sort(all(Qu));  // 쿼리 정렬

    // 이전 쿼리의 결과를 이용해 계산해나가기

    // 먼저 이렇게 안하고 0부터 while문 돌렸다가 Minus에서 deque가 비어있어서 틀렸음
	int s = Qu[0].s, e = Qu[0].e;
	for(int i=s; i<=e; i++){
		Plus(i, false);  // while(e<Qu[i].e) Plus(++e, false); 와 같은 작업
	}
	ans[Qu[0].idx] = query();

    for(int i=0;i<M;++i){
        // 순서 중요
        // pop해버리면 안됨
        while(s>Qu[i].s) Plus(--s, true);
        while(e<Qu[i].e) Plus(++e, false);
        while(s<Qu[i].s) Minus(s++, true);
        while(e>Qu[i].e) Minus(e--, false);
        ans[Qu[i].idx] = query();
    }

    for(int i=0; i<M; ++i) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}