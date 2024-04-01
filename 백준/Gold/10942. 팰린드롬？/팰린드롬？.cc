#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100001

/*

*/

int N,M;
int num[MAX];

// s와 e의 합이 i일때 e-s가 몇까지 팰린드롬인지
int palindrome[2*MAX];

void makedp(int s, int e){

    palindrome[s+e] = e-s;

    s--; e++;
    if (s<=0 || e>N) return;
    
    if (num[s]==num[e]){
        makedp(s, e);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    FOR(i,1,N){
        cin >> num[i];
    }

    // 홀수 팰린드롬
    FOR(i,1,N){
        makedp(i,i);
    }

    // 짝수 팰린드롬
    FOR(i,2,N){
        if (num[i]==num[i-1])
            makedp(i-1,i);
    }

    cin >> M;
    FOR(i,1,M){
        int s, e;
        cin >> s >> e;
        if (palindrome[s+e] >= e-s){
            cout << 1 << '\n';
        }
        else cout << 0 << '\n';
    }
    
    return 0;
}