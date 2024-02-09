#include <iostream>
using namespace std;

int main(void){
    int N, M;
    int A[101][101], B[101][101];
    cin >> N >> M;
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> B[i][j];
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << A[i][j]+B[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}