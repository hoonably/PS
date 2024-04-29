#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,box) for(int i=(a);i<(box);i++)
#define all(v) v.begin(), v.end()
#define MAX 10000

/*

*/

bool cmp(int a, int box) {
    return a > box;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;

    cin >> N;
    vector<int> crain(N);
    FOR(i,0,N){
        cin >> crain[i];
    }

    cin >> M;
    vector<int> box(M);
    FOR(i,0,M){
        cin >> box[i];
    }

    sort(all(crain), cmp);
    sort(all(box), cmp);

    // 못옮기는 박스가 존재
    if (box[0] > crain[0]) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    // 가장 제한이 작은 크레인이 최대 몇개를 옮길 수 있는지
    while (!box.empty()) {
        cnt++;
        int idx = 0;
        // 크레인 가장 큰 무게 부터
        for (int i = 0; i < crain.size(); i++) {
            while (idx < box.size() && box[idx] > crain[i]) {
                idx++;
            }
            if (idx < box.size()) {
                box.erase(box.begin() + idx);  // 처리된 박스 제거
            }
        }
    }
    cout << cnt;
    
    return 0;
}