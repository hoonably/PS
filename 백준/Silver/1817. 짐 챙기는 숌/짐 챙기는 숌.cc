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
https://www.acmicpc.net/problem/1817
차례대로만 박스에 넣을 수 있음
*/

#define MAX 

int N, M;
int book;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    int box = 0;
    int area = 0;
    for(int i=0; i<N; i++){
        cin >> book;

        // 최근 박스에 넣을 수 있음
        if(area >= book){
            area -= book;
        }

        // 새 박스에 넣어야함
        else {
            box++;
            area = M-book;
        }
    }

    cout << box;

    
    return 0;
}