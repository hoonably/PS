#include <stdio.h>

int main(void){
    char S[101];
    int locations[26];
    for (int i=0; i<26; i++){
        locations[i]=-1;
    }
    scanf("%s", S);
    for (int i=0; S[i]!='\0'; i++){
        if (locations[S[i]-'a']==-1){
            locations[S[i]-'a']=i;
        }
    }
    for (int i=0; i<26; i++){
        printf("%d ", locations[i]);
    }
    return 0;
}