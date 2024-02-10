#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    set<string> A;
    cin >> S;
	set<string> ss_set;

    int len = S.length();

	for (int i = 0; i < len; i++) {
		for (int j = 1; i+j <= len; j++) {
            // substr(시작지점, 길이)
			ss_set.insert(S.substr(i, j));
		}
	}

	cout << ss_set.size();

    
    return 0;
}