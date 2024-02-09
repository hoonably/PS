#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, A, B;
    cin >> T;
    for (int i=1; i<=T; i++){
        cin >> A >> B;
        cout << "Case #" << i << ": " << A+B << endl;
    }
    return 0;
}