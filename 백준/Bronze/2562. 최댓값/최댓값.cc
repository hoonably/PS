#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int get_num, big_index, big_value=0;
     for (int i=0; i<9; i++){
        cin >> get_num;
        if (get_num>big_value){
            big_index = i;
            big_value = get_num;
        }
     }
     cout << big_value << endl << big_index+1;

    return 0;
}