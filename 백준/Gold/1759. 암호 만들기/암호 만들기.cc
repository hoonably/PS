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

int L, C;
vector<char> alphabet;

bool check(char c){
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

void print(int level, int lastidx, int cnt, string str){

    // 최소 한개의 모음, 두개의 자음
    // 모음 개수 1~L-2개
    if (cnt>L-2) return;

    if (level==L && cnt>=1) {
        cout << str << '\n';
        return;
    }

    ++level;
    for(int i=lastidx+1; i<C; i++){
        print(level, i, cnt+check(alphabet[i]), str+alphabet[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> L >> C;
    for(int i=0; i<C; i++){
        char c;
        cin >> c;
        alphabet.emplace_back(c);
    }
    sort(all(alphabet));

    print(0, -1, 0, "");
    
    return 0;
}