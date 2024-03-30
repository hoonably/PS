#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*
새로운 숫자의 나머지 구하기
 - 123이라는 숫자에 456이라는 숫자가 붙었다. 그러면, 123*100 + 456으로 표현할 수 있다.
123456 % K = (123*100)%K + 456%K 로 나타낼 수 있고, (123%K)*(100%K) +456%K 로 나타낼 수 있다.

여기서 123%K 값, 100%K 값, 456%K 값을 미리 알고 있으면 계산이 빠르다.

50자리까지 가능하므로 10^1 부터 10^50 % K 값까지 미리 저장해놓자.
*/



int N,K;
string num[15];
int temRemain[51];
int numRemain[15];

// dp[i][k] : i 비트일때 나머지가 k인 것의 경우의 수
ll dp[1 << 15][100];

//x를 k로 나눈 나머지 반환
int get_mod(string x, int k) {
	int tmp = 0;
	for (int i = 0; i < x.size(); i++) {
		tmp *= 10;
		tmp += x[i] - '0';
		tmp %= k;
	}
	return tmp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> num[i];
    }
    cin >> K;

    dp[0][0] = 1;
    
    // 10의 0제곱부터 50제곱까지 K로 나눈 나머지 저장
	temRemain[0] = 1 % K;
	for (int i = 1; i <= 50; i++) 
		temRemain[i] = (temRemain[i - 1] * 10) % K;
	
    // 숫자들을 각각 K로 나눈 나머지 저장
	for (int i = 0; i < N; ++i)
		numRemain[i] = get_mod(num[i], K);

    // dp 실행
	for(int cur = 0; cur < (1 << N); ++cur){

		for (int i = 0; i < N; ++i) {
			if ((cur & (1 << i)) == 0) {
			
				int nxt = cur | (1 << i);
 
				for (int j = 0; j < K; ++j) {
                    // 다음 나머지 구하기
					int nxtRemain = ((j * temRemain[num[i].length()]) % K + numRemain[i]) % K;
					dp[nxt][nxtRemain] += dp[cur][j];
				}
			}
		}
	}


    // 기약분수 답 계산하기

    // 분자
    ll up = dp[(1 << N) - 1][0];  // 나누어 떨어지는 dp

    // 분자가 0이라면
    if (up==0) cout << "0/1";

    else { 
        // 분모 factorial 계산
        ll down = 1;
        for (int i=2; i<=N; i++) down*=i;

        // 기약분수로 변경
        ll div = gcd(up, down);
        cout << up / div << '/' << down / div;
    }
    
    return 0;
}