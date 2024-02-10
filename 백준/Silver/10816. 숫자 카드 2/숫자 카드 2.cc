#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, get_num;
    // map 선언
    map<int, int> card;
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> get_num;
        // map에 없다면
        if(card.find(get_num) == card.end()){
            card[get_num] = 1;
        }
        else{
            card[get_num]++;  // 있다면 1 올리기
        }
        
    }
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> get_num;
        if (card.find(get_num) == card.end()){
            cout << "0 ";
        }
        else cout << card[get_num] << ' ';
    }

    return 0;
}