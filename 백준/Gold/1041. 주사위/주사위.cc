#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX

/*
모든 면의 모서리를 제외하고는 가장 작은 수로 채운다.

최적의 해를 보자.

윗면

AAAA
AAAA
AAAA
AAAA

옆면

BBBC
AAAB
AAAB
AAAB

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    // 예외처리 N==1
    if (N==1) {
        cout << A+B+C+D+E+F-max({A,B,C,D,E,F});
        return 0;
    }
    
    if (A>F) swap(A,F);
    if (B>E) swap(B,E);
    if (C>D) swap(C,D);

    // A, B, C 가 작은 값으로 배정됨
    // D, E, F는 나올리가 없음 이제

    // A B C 정렬
    if (B<A) swap(A,B);
    if (C<A) swap(A,C);
    if (C<B) swap(B,C);

    // 옆면
    ll ans = A*(N-1)*(N-1) + B*2*(N-1) + C;
    ans *= 4;

    // 윗면
    ans += A*N*N;

    cout << ans;

    return 0;
}