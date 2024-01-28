#include <stdio.h>

int main(void){
    int get_num, big_index, big_value=0;
     for (int i=0; i<9; i++){
        scanf("%d", &get_num);
        if (get_num>big_value){
            big_index = i;
            big_value = get_num;
        }
     }
     printf("%d\n%d", big_value, big_index+1);

    return 0;
}