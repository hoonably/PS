#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        char word[1001];
        scanf("%s", word);
        int cnt = 0;
        while (word[cnt] != '\0'){
            cnt++;
        }
        printf("%c%c\n", word[0], word[cnt-1]);
    }
    return 0;
}