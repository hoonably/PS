#include <iostream>
using namespace std;

int main(){
    //  10000/10000까지 있다.
    //  1+2+3+4+...+n = n*(n+1)/2
    
    int get_a, sum = 0;
    cin >> get_a;

    for(int i=1;i<=14142;i++) {		// i=14142 일때 계산한게 1억이 넘음
        if(i*(i-1)/2>=get_a) {
            sum = i; // i는 분모와 분자의 합을 의미한다.
            break;
        }
    }
    int sum_last = (sum-1)*(sum-2)/2; //앞에 뺄 거
    int rest = get_a - sum_last; //빼고 나머지
    
    //합이 2,4,6 => 1/2 ->2/1
    //합이 3 => 3/1 -> 3/2 -> 3/3
    if(sum%2==0) {
        cout << sum-rest << "/" << rest;
    }
    else {
        cout << rest << "/" << sum-rest;
    }
    
    return 0;
}