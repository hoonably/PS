#include <stdio.h>

int main(void){
    int N, get_Num, max=0;
    float sum=0;
    scanf("%d", &N);
    int scores[N];
    for (int i=0; i<N; i++){
        scanf("%d", &get_Num);
        scores[i] = get_Num;
        sum += get_Num;
        if (get_Num>max){
            max = get_Num;
        }
    }
    sum = sum / max * 100;
    printf("%f", sum/N);

    return 0;
}