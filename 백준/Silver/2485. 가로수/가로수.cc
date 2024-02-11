#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, first_loc, last_loc, now_loc, now_gcd;
    cin >> N;

    // 첫번째, 두번째만 따로 받아서 gcd 저장
    cin >> first_loc >> last_loc;
    now_gcd = last_loc - first_loc;

    for (int i=0; i<N-2; i++){
        cin >> now_loc;
        now_gcd = gcd(now_gcd, now_loc - last_loc);
        last_loc = now_loc;
    }

    // 총 거리
    int all_dist = now_loc - first_loc;
    // 총 거리를 gcd로 나누고, 있는 가로등의 개수를 빼준 후 1 추가
    cout << (all_dist / now_gcd) - N + 1;

    
    return 0;
}