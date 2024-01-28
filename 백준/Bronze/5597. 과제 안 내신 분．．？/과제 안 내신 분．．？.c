#include <stdio.h>

int main(void){
    int arr[31], n;
    for (int i=1; i<31; i++){
        arr[i]=0;
    }
    for (int i=0; i<28; i++){
        scanf("%d", &n);
        arr[n]=1;
    }
    for (int i=1; i<31; i++){
        if (arr[i]==0){
            printf("%d\n", i);
        }
    }
    return 0;
}