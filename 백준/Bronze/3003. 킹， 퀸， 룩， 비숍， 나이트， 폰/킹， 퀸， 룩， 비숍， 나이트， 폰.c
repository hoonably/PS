#include <stdio.h>

int main(){
    int chess[] = {1,1,2,2,2,8};
    for (int i=0;i<6;i++){
        int temp;
        scanf("%d", &temp);
        chess[i]-=temp;
    }
    for (int i=0; i<6; i++){
        printf("%d ", chess[i]);
    }
    return 0;
}