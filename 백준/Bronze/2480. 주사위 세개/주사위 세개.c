#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans;
    if (a==b && b==c){
        ans = 10000 + a*1000;
    }
    else if (a==b || b==c){
        ans = 1000 + b*100;
    }
    else if (a==c){
        ans = 1000 + a*100;
    }
    else{
        if (a>=b & a>=c){
            ans = a*100;
        }
        else if (b>=c){
            ans = b*100;
        }
        else{
            ans = c*100;
        }
    }
    printf("%d", ans);
    return 0;
}