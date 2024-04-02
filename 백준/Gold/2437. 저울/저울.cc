#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
무게가 양의 정수인 N개의 저울추가 주어질 때, 
이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구함

단, 한쪽으로만 추를 올려놓기 때문에 쉬움

가지고 있는 저울추들로 1,2,3,4 무게를 만들 수 있다면
그 다음에 저울추가 5가 나왔다면 5~9까지 만들 수 있음

하지만 6이 나왔다면 5는 못만들음.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    int W[1001];

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> W[i];
    }

    sort(W, W+N);

    // 진행중인 상황에서 최대로 만들 수 있는 값
    int able = 0;
    for (int i=0; i<N; i++){

        // able + 1은 못 만드는 상황이 옴
        if (able + 1 < W[i]){
            break;
        }
        
        able += W[i];
    }
    cout << able+1;
    
    return 0;
}