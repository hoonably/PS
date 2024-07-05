#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

string A, B;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> A >> B;
    int Alen = A.length();
    int Blen = B.length();

    if (Alen<Blen){
        swap(A,B);
        swap(Alen, Blen);
    }

    // 자리수 차이만큼 B 앞에 더해주기
    string zero = "";
    for(int i=0; i<Alen-Blen; i++){
        zero+='0';
    }
    B = zero + B;

    stack<int> st;

    bool up = false;  // 이전에 올림이 있는가?
    for(int i=Alen-1; i>=0; i--){
        int temp = A[i]-'0' + B[i]-'0' + up;
        
        if(temp>=10){
            up = true;
            st.push(temp-10);
        }
        else{
            up = false;
            st.push(temp);
        }
    }

    // 마지막 자리수도 올림이 있다면
    if (up) cout << '1';

    for(int i=0; i<Alen; i++){
        cout << st.top();
        st.pop();
    }
    
    return 0;
}