#include <stdio.h>

// void swap(&a, &b){
//     int temp = *a;
//     *a = *b;

// }

int main(void){
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    int basket[N+1];
    for (int i=1; i<=N; i++){
        basket[i]=i;
    }

    for (int t=0; t<M; t++){
        scanf("%d %d", &i, &j);
        int temp = basket[i];
        basket[i] = basket[j];
        basket[j]=temp;

        // swap(&i, &j);
    }
    for (int i=1; i<=N; i++){
        printf("%d ", basket[i]);
    }
}