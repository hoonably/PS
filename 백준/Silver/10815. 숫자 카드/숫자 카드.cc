#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, get_num;
    // 집합 선언
    set<int> card;
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> get_num;
        card.insert(get_num);
    }
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> get_num;
        // find(요소) : 요소가 나오면 그 주소 반환
        // 그러므로 반환값이 end 주소라면 없는것임
        if (card.find(get_num) == card.end()){
            cout << "0 ";
        }
        else cout << "1 ";
    }

    return 0;
}