#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 200'001

/*
log2의 시간으로 줄이는 방법
fn(x) 를 구할때
n=11이라면
f11(x) = f8(f2(f(x)))
로 구하면 되기 때문에 2의 제곱수만 구해놓으면 된다.
n = 500000 이므로 (int)log2(500000) 까지 구해놓자.
*/

int m;
int f[20][MAX];  // log2(500000) = 18.xxxx 이므로

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // 기본 함수 입력
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> f[1][i];
    }

    for (int i=2; i<=19; i++) 
		for (int j=1; j<=m; j++) 
			f[i][j] = f[i-1][f[i-1][j]];

    int Q;
    cin >> Q;
    for (int i=0; i<Q; i++){
        int n, x;
        cin >> n >> x;
        // fn(x) 구하기
        // 여기서 i는 2의 i제곱을 의미
        // n을 계속 2로 나누면서 n이 홀수일 경우 x값을 f[i][x] 로 바꿔줌
        for (int i=1; n!=0; i++){
            if (n%2==1){
                x = f[i][x];
            }
            n >>= 1;  // 2로 나누기
        }
        cout << x << '\n';
    }

    return 0;
}