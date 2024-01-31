#include <stdio.h>

int main(){
    int get_num, max_value=-1, max_row, max_column;
    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            scanf("%d", &get_num);
            if (get_num > max_value){
                max_value = get_num;
                max_row = i;
                max_column = j;
            }
        }
    }
    printf("%d\n%d %d\n", max_value, max_row, max_column);

    return 0;
}