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

#define MAX 100000

struct QueryNode {
    // i j: Ai, Ai+1, ..., Aj에 존재하는 서로 다른 수의 개수

    int i, j, idx;
    int sqrtN;

    QueryNode() : QueryNode(0, 0, -1, 0) {}
    QueryNode(int i, int j, int idx, int N) : i(i), j(j), idx(idx) { sqrtN = sqrt(N); }

    // (s/√N, e) 순으로 오름차순 정렬
    bool operator <(const QueryNode& A)const {
        if (i / sqrtN != A.i / sqrtN)
            return (i / sqrtN < A.i / sqrtN);
        return (j < A.j);
    }
};

int N, M, A[MAX];
int result[MAX];
int dcnt = 0, cnt[1000001];
QueryNode Q[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    cin >> M;
    for (int idx = 0; idx < M; ++idx) {
        int i, j;
        cin >> i >> j;
        Q[idx] = QueryNode(i - 1, j, idx, N);
    }
    sort(Q, Q + M);  // 쿼리 정렬

    // 첫 번째에 위치한 쿼리의 결과는 손수 구하기
    int i0 = Q[0].i, j0 = Q[0].j;
    for (int i = i0; i < j0; ++i){
        if (cnt[A[i]]++ == 0){
            ++dcnt;
        }
    }
    result[Q[0].idx] = dcnt;

    // 다음 쿼리부터 바로 이전 쿼리의 결과를 사용해 계산해 나가기
    for (int i = 1; i < M; ++i) {
        while (Q[i].i < i0) if (cnt[A[--i0]]++ == 0) ++dcnt;
        while (j0 < Q[i].j) if (cnt[A[j0++]]++ == 0) ++dcnt;
        while (Q[i].i > i0) if (--cnt[A[i0++]] == 0) --dcnt;
        while (j0 > Q[i].j) if (--cnt[A[--j0]] == 0) --dcnt;
        result[Q[i].idx] = dcnt;
    }

    for (int i = 0; i < M; ++i)
        cout << result[i] << "\n";
    
    return 0;
}