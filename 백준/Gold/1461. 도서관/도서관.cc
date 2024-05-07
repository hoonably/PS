#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
책 N권, 한번에 들 수 있는 책 M개
마지막에 0으로 돌아올 필요는 없음 : 마지막에 가장 먼 곳 가기
*/

#define MAX 50

int N, M;
vector<int> book1, book2;  // 음수 책, 양수 책

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        int book;
        cin >> book;
        if (book<0) book1.push_back(-book);
        else book2.push_back(book);
    }

    sort(all(book1));
    sort(all(book2));

    int book1Size = book1.size();
    int book2Size = book2.size();

    int book1Max = 0;
    int book2Max = 0;

    // 7개인데 M=3 이라면
    // 7, 4, 1 번째
    int ans = 0;

    if (book1Size!=0){
        int idx = book1Size-1;
        book1Max = book1[idx];
        while(true){
            if (idx==0){
                ans += book1[0];
                break;
            }
            else if (idx<0) break;
            ans += book1[idx];
            idx -= M;
        }
    }

    if (book2Size!=0){
        int idx = book2Size-1;
        book2Max = book2[idx];
        while(true){
            if (idx==0){
                ans += book2[0];
                break;
            }
            else if (idx<0) break;
            ans += book2[idx];
            idx -= M;
        }
    }

    // 기존 값은 왕복해야함
    ans *= 2;

    // 둘 중 먼 곳은 왕복 안함
    ans -= max(book1Max, book2Max);
    
    cout << ans;
    
    return 0;
}