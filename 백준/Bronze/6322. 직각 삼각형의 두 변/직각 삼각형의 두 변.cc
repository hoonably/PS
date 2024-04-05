#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    
    int T=1;

    while(true){
        double a, b, c;
        cin >> a >> b >> c;
        if (a==0) break;

        cout << "Triangle #" << T << '\n';

        if (a==-1){
            a = sqrt(c*c - b*b);
            if (a>0 && a+b>c){
                printf("a = %.3f", a);
            }
            else {
                cout << "Impossible.";
            }
        }
        else if (b==-1){
            b = sqrt(c*c - a*a);
            if (b>0 && a+b>c){
                printf("b = %.3f", b);
            }
            else {
                cout << "Impossible.";
            }
        }
        else {
            c = sqrt(a*a + b*b);
            if (a+b>c){
                printf("c = %.3f", c);
            }
            else {
                cout << "Impossible.";
            }
        }
        T++;
        cout << "\n\n";
    }
    
    return 0;
}