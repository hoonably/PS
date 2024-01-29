#include <stdio.h>

int main(void){
    char S[1001];
    int i;
    scanf("%s %d", S, &i);
    printf("%c", S[i-1]);
    return 0;
}