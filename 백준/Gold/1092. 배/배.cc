#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX 10000

/*

*/

bool cmp(int a, int b) {
    return a > b;
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
        // 크레인 가장 큰 무게 부터
        for (int i = 0; i < crain.size(); i++) {
            // 상자 가장 큰 무게 부터
            for (int j = 0; j < box.size(); j++) {
                // 옮길 수 있으면 삭제하고 다음 크레인으로
                if (crain[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    cout << cnt;
    
    return 0;
}