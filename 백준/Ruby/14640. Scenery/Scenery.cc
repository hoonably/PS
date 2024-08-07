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
https://www.acmicpc.net/problem/14640

그리디 끝판왕 문제
ICPC World Finals 2017
에서 한명도 풀지 못했음.

보고 배울 가치가 있다고 생각해 참고하고 코드를 따라써보고 이해해봄.

https://t1.daumcdn.net/cfile/tistory/99765B4B5B75BC1B0B
*/

#define MAX 10001
#define left first
#define right second

pii seg[MAX];
int n, t;
int r[MAX], rtemp[MAX], lim[MAX], cur[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    
    // 각 사진을 찍을 수 있는 기간
    for (int i = 1; i <= n; i++){
        cin >> seg[i].left >> seg[i].right;
        r[i] = seg[i].right;
    }

    sort(seg + 1, seg + n + 1);
    sort(r + 1, r + n + 1);

    // cur을 모두 n으로 설정
    fill(cur+1, cur+n+1, n);

    // r을 rtemp에 복사
    copy(r+1, r+n+1, rtemp+1);

    // lim INF 초기화
    memset(lim, 0x3f, sizeof(lim));

    for (int i = n; i>0; i--) {

        // 인덱스를 큰거부터 줄여나가면서 확인
        // seg[i].right 가 더 크다면 반복 종료
        for (int j = n; j && r[j] >= seg[i].right; j--) {

            // 각 사진을 찍는데 걸리는 시간 빼주기
            rtemp[j] -= t;

            // rtemp의 최소값 구하기
            while (rtemp[j] < seg[cur[j]].left && cur[j]){
                rtemp[j] = min(rtemp[j], lim[cur[j]--]);
            }
            
            // seg[i]의 left가 rtemp[j]를 넘어가는게 있다면 모두 찍을 수 없음
            if (rtemp[j] < seg[i].left){
                cout << "no";
                return 0;
            }

            lim[i] = min(lim[i], rtemp[j] - t);
        }
    }

    cout << "yes";
    
    return 0;
}