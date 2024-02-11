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

    // n1/n2 + m1/m2
    int n1, n2, m1, m2, denominator, numerator, temp_gcd;
    cin >> n1 >> n2 >> m1 >> m2;
    denominator = n2 * m2;  // 분모
    numerator = n1*m2 + m1*n2;  // 분자
    temp_gcd = gcd(denominator, numerator);
    cout << numerator / temp_gcd << ' ' << denominator / temp_gcd;
    
    return 0;
}