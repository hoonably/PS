#include <iostream>
using namespace std;

int main(void){
    int h, m, c;
    cin >> h >> m >> c;
    int hour_c = c/60;
    int minute_c = c%60;
    m += minute_c;
    if (m>=60){
        h+=1;
        m-=60;
    }
    h += hour_c;
    if (h>=24){
        h-=24;
    }
    cout << h << " " << m;

    return 0;
}
