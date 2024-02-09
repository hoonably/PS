#include <iostream>
using namespace std;

int main(void){
    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m<0){
        h-=1;
        m+=60;
    }
    if (h<0){
        h+=24;
    }
    cout << h << " " << m;

    return 0;
}