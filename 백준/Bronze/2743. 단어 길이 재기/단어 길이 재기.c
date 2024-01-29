#include <stdio.h>

int main(void){
    char word[101];
    scanf("%s", word);
    int cnt = 0;

    // 시간복잡도 빠름
    while (word[cnt] != '\0'){
        cnt++;
    }

    // 시간복잡도 느림
    // int cnt = strlen(word); 
    printf("%d", cnt);


    return 0;
}