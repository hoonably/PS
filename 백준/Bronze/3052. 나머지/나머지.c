#include <stdio.h>

int main(void){
    int divArray[42]={0}, num, cnt=0;
    for (int i=0; i<10; i++){
        scanf("%d", &num);
        if (divArray[num%42]==0){
            cnt++;
            divArray[num%42]^=1;
        }
    }
    printf("%d", cnt);

    return 0;
}