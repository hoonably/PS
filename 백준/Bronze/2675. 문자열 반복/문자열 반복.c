#include <stdio.h>

int main(void){
    int T, R;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        scanf("%d", &R);
        char word[1001];
        scanf("%s", word);
        for (int j=0; word[j]!='\0'; j++){
            for (int k=0; k<R; k++){
                printf("%c", word[j]);
            }
        }
        printf("\n");
    }
    return 0;
}