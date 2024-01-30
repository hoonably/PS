#include <stdio.h>

int main(void){
    char get_word[15];
    int alphabet, cnt=0;
    scanf("%s", get_word);
    for (int i=0; get_word[i]!='\0'; i++){
        alphabet = get_word[i];
        if(alphabet <= 'C'){
            cnt += 3;
        }
        else if(alphabet <= 'F'){
            cnt += 4;
        }
        else if(alphabet <= 'I'){
            cnt += 5;
        }
        else if(alphabet <= 'L'){
            cnt += 6;
        }
        else if(alphabet <= 'O'){
            cnt += 7;
        }
        else if(alphabet <= 'S'){
            cnt += 8;
        }
        else if(alphabet <= 'V'){
            cnt += 9;
        }
        else if(alphabet <= 'Z'){
            cnt += 10;
        }
    }
    printf("%d", cnt);
    return 0;
}