#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, cnt=0;
    string get_str;
    // 집합 선언
    set<string> card;
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> get_str;
        card.insert(get_str);
    }
    for (int i=0; i<M; i++){
        cin >> get_str;
        // find(요소) : 요소가 나오면 그 주소 반환
        // 그러므로 반환값이 end 주소라면 없는것임
        if (card.find(get_str) != card.end()){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}