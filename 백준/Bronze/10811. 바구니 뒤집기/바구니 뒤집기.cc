#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int N, M, a, b;
    int basket[101];

    cin >> N >> M;

    for (int i=0; i<N+1; i++){
        basket[i]=i;
    }

    for (int i=0; i<M; i++){
        cin >> a >> b;
        while (a < b){
            swap(&basket[a], &basket[b]);
            a++; 
            b--;
        }
    }

    for (int i=1; i<N+1; i++){
        cout << basket[i] << ' ';
    }

    return 0;
}