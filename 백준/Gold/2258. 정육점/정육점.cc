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
현재 가격보다 '저렴한' 것은 그냥 줌.
가격이 같을 경우 처리를 잘 해주자.
*/

#define MAX 

struct meat{
    int weight, price;
    bool operator<(const meat &a) const {
        if (price==a.price) return weight>a.weight;
        return price<a.price;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<meat> arr(n);
    for(auto &u : arr) {
        cin >> u.weight >> u.price;
    }
    sort(all(arr));

    unsigned int ans = 3e9 + 1;
    unsigned int wsum = 0, psum = 0;

    for(int i = 0; i < n; i++) {
        wsum += arr[i].weight;
        if(i > 0 && arr[i-1].price == arr[i].price) {
            psum += arr[i].price;
        }
        else {
            psum = 0;
        }
        if(wsum >= m) {
            ans = min(ans, psum + arr[i].price);
        }
    }
    if(ans == 3e9+1) cout << "-1";
    else cout << ans;
    
    return 0;
}   