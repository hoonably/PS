#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
굳이 분할정복할때 새로운 배열을 계속 만들어주지말고, 
2x2 배열의 맨 앞의 값을 2번째로 큰 수로 변경해주고,
다음 단계로 갈수록 비교할때 2^n 차이씩 비교를 해주면 된다.
*/

int arr[1024][1024];
int level;

void change(int x, int y){
    int temp[4];
    temp[0] = arr[x][y];
    temp[1] = arr[x+level][y];
    temp[2] = arr[x][y+level];
    temp[3] = arr[x+level][y+level];
    sort(temp, temp+4);
    arr[x][y] = temp[2];  // 두번째로 큰 수를 가장 앞으로
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    
    cin >> N;
    for (int i=0; i<N;i++){
        for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    level = 1; // 한칸씩 비교로 시작
    while (level<N){
        for (int x=0; x<N; x+=2*level){
            for (int y=0; y<N; y+=2*level){
                change(x, y);
            }
        }
        level *= 2;
    }
    cout << arr[0][0];

    return 0;
}