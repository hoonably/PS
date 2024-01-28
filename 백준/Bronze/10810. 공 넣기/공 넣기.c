#include <stdio.h>

 int main(void){
    int N, M, i, j, k;
    scanf("%d %d", &N, &M);
    int arr[N];
    for (int t=0; t<N; t++){
        arr[t] = 0;
    }
    // 공 바꿔주기
    for (int t=0; t<M; t++){
        scanf("%d %d %d", &i,&j,&k);
        for (int temp=i-1; temp<j; temp++){
            arr[temp]=k;
        }
    }
    for (int t=0; t<N; t++){
        printf("%d ", arr[t]);
    }

    return 0;
 }