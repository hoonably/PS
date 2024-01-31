#include <stdio.h>

int main(void){
    char word[1000001];
    int alphabet[26] = {0};
    scanf("%s", word);
    int i=0;
    while (word[i]!='\0'){

        if (65 <= word[i] && word[i] <= 90){
            alphabet[word[i]-65]++;
        }
        else {
            alphabet[word[i]-97]++;
        }
        i++;
    }

    // for (int j=0; j<26; j++){
    //     printf("%d ", alphabet[j]);
    // }

    int best_value = 0;
    int best_index = 0;
    int only = 0;
    for (int j=0; j<26; j++){
        if (alphabet[j] > best_value){
            best_index = j;
            best_value = alphabet[j];
            only = 1;
        }
        else if (alphabet[j] == best_value){
            only = 0;
        }
    }

    // 가장 많이 사용된 알파벳이 하나
    if (only){
        printf("%c", best_index+65);
    }
    else{
        printf("?");
    }
    return 0;
}