#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    N/=4;
    for (int i=0; i<N; i++){
        printf("long ");
    }
    printf("int");
    return 0;
}