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

*/

#define MAX 

char rbuf[1<<16];
int idx, ridx;
inline char read(){
    if(ridx == idx){
        ridx = fread(rbuf, 1, 1<<16, stdin);
        if(!ridx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}
inline int readInt(){
    int sum = 0;
    char now = read();
    while(now <= 32) now = read();
    while(now >= 48) sum = sum * 10 + now - '0', now = read();
    return sum;
}

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    n = readInt();
	vector<int> book(n);
	for (int &i : book) i = readInt();

	int cnt = n;
	for (int i = n - 1; i >= 0; i--) {
		if (book[i] == cnt)
			cnt--;
	}
	cout << cnt;

    return 0;
}