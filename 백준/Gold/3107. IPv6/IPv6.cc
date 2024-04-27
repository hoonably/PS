#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
4자리씩 8개
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int part = 0;

	string str, s;
	vector<string> v, ans;

	cin >> str;

	istringstream ss(str);

    // : 나올때까지 s에 담기
	while (getline(ss, s, ':')) {
		int len = s.size();
		if (len) {
			part++;
            while (len < 4) {
                s = "0" + s;
                len++;
            }
		}
		else if (len == 0)	s = "-1";  // 연속표시
		v.push_back(s);
	}

	bool add = false;
	for (string s : v) {

        // 연속 ::
		if (s == "-1") {
			if (!add) {
				for (int i=0; i < 8-part; i++) {
					ans.push_back("0000");
				}
				add = true;
			}
		}
		else ans.push_back(s);
	}
	for (int i = 0; i < 8; i++) {
		cout << ans[i];
		if (i < 7) cout << ":";
	}
	return 0;
}