#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int N, K, ans;
int use[101];
int lastFind[101];  // 각 물건이 마지막으로 언제 나오는지 기록
set<int> plug;

// 이후에 남은 것 중에 가장 나중에 나오는 원소를 뽑기
// 없다면 그걸 뽑기
int find_lastest(int idx){

    int res = 0;  // 가장 나중에 나오는 원소
    int lastIdx = -1;  // 가장 나중에 나오는 원소의 idx
    for (int num : plug){
        // 뒤에 그 숫자가 더이상 안나온다면 바로 그거 뽑기
        if (lastFind[num] < idx){
            return num;
        }
        // 현재 idx 다음부터 num가 나올때까지 탐색
        int numIdx = find(use+idx, use+K, num) - use;
        if (numIdx > lastIdx){
            res = num;
            lastIdx = numIdx;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i=1; i<=K; i++){
        cin >> use[i];
        lastFind[use[i]] = i;
    }

    for (int i=1; i<=K; i++){
        plug.insert(use[i]);

        // 멀티탭 개수가 부족하다면
        if (plug.size()>N){
            ans++;
            // cout << find_lastest(i) << " 뽑음 / ";
            plug.erase(find_lastest(i));
        }
    }
    cout << ans;
    
    return 0;
}