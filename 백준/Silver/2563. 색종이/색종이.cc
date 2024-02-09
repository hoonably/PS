#include <iostream>
using namespace std;

int main(){
    bool square[100][100] = {false, };
    int N, cnt = 0;
    cin >> N;
    
    for (int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        for (int j=x; j<x+10; j++){
            if (j==100) continue;
            for (int k=y; k<y+10; k++){
                if (k==100) continue;
                square[j][k] = true;
            }
        }
    }
    for (int j=0; j<100; j++){
        for (int k=0; k<100; k++){
            if (square[j][k] == true) cnt++;
        }
    }
    cout << cnt;
    return 0;
}