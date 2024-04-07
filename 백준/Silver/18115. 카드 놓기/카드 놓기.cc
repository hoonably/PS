#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1000001

/*
5 4 3 2 1 순서로 내려놔야함.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    int skill[MAX];
    deque<int> card;

    for (int i=N; i>=1; i--){
        cin >> skill[i];
    }

    for (int i=1; i<=N; i++){

        if (skill[i]==1){
            // 카드를 위에 올려놓음
            card.push_front(i);
        }
        else if (skill[i]==2){
            // 카드를 위에서 두번째에 넣음
            int temp = card.front();
            card.pop_front();
            card.push_front(i);
            card.push_front(temp);
        }
        else {
            // 카드를 맨 아래에 넣음
            card.push_back(i);
        }
    }

    while(!card.empty()){
        cout << card.front() << ' ';
        card.pop_front();
    }
    
    return 0;
}