#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    char num_list_1[4], num_list_2[4];
    int num1, num2;
    scanf("%s %s", num_list_1, num_list_2);
    swap(num_list_1, num_list_1+2);
    swap(num_list_2, num_list_2+2);
    // <stdlib.h> 를 사용해 char문자열 int로 변환
    num1 = atoi(num_list_1);
    num2 = atoi(num_list_2);
    if (num1>=num2){
        printf("%d", num1);
    }
    else{
        printf("%d", num2);
    }
    return 0;
}