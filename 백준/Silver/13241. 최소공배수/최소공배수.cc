#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

lld gcd(lld a, lld b) {
	lld c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

lld lcm(lld a, lld b) {
	return (a * b) / gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld A, B;
    cin >> A >> B;
    cout << lcm(A, B);
    
    return 0;
}