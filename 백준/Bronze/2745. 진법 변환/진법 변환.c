#include <stdio.h>
#include <math.h>

int main(){
    char N[33];
    int B, length=0, intArr[33], ans=0;

    scanf("%s %d", N, &B);
    
    while (N[length]!='\0'){
        // 알파벳이라면
        if (N[length]>=65){
            intArr[length] = N[length]-65+10;
        }
        // 숫자라면 (0의 아스키코드는 48)
        else{
            intArr[length] = N[length]-48;
        }
        length++;
    }

    for (int i=length-1; i>=0; i--){
        ans += intArr[i] * pow(B, length-1-i);
    }

    printf("%d", ans);

    return 0;
}