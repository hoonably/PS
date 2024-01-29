#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    int basket[N+1];
    for (int i=0; i<N+1; i++){
        basket[i]=i;
    }
    for (int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        while (a<b){
            swap(&basket[a], &basket[b]);
            a++; b--;
        }
    }
    for (int i=1; i<N+1; i++){
        printf("%d ", basket[i]);
    }

    return 0;
}