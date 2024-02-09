#include <iostream>
using namespace std;

 int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, i, j, k;
    int arr[101];

    cin >> N >> M;
    
    for (int t=0; t<N; t++){
        arr[t] = 0;
    }
    // 공 바꿔주기
    for (int t=0; t<M; t++){
        cin >> i >> j >> k;
        for (int temp=i-1; temp<j; temp++){
            arr[temp]=k;
        }
    }
    for (int t=0; t<N; t++){
        cout << arr[t] << ' ';
    }

    return 0;
 }