#include <iostream>
using namespace std;

// swap 함수 연습해보기
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int N, M, i, j;
    cin >> N >> M;
    int basket[N+1];
    for (int i=1; i<=N; i++){
        basket[i]=i;
    }

    for (int t=0; t<M; t++){
        cin >> i >> j;
        // 두 방법 모두 가능하다.
        // swap(&basket[i], &basket[j]);
        swap(basket+i, basket+j);
    }

    for (int i=1; i<=N; i++){
        cout << basket[i] << ' ';
    }
}