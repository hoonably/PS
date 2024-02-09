#include <iostream>
using namespace std;

int main(void){
    int divArray[42] = {false};
    int num, cnt=0;
    for (int i=0; i<10; i++){
        cin >> num;
        if (divArray[num%42] == false){
            cnt++;
            divArray[num%42] = true;
        }
    }
    cout << cnt;

    return 0;
}