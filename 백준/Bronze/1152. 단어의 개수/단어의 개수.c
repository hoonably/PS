#include <stdio.h>
#include <string.h>

int main(void) {
    char word[1000000];
    int count = 0, len;
    
    // 엔터 입력할때까지 scanf 받기
    scanf("%[^\n]s", word);
    len = strlen(word);
    
    // 띄어쓰기만 있을 경우 0 출력
    if (len == 1 && *word == ' ') {
        printf("%d", count);
        return 0;
    }
    
    for (int i = 1; i < len - 1; i++) {
        if (*(word+i) == ' ') {
            count++;
        }
    }
    printf("%d", count + 1);
    
    return 0;
}