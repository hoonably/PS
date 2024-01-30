#include <stdio.h>

int main(){
    char word[101];
    int len=0;
    scanf("%s", word);
    while(word[len]!='\0'){
        len++;
    }
    for (int i=0; i<len/2; i++){
        if (word[i]!=word[len-i-1]){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}