#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int get_num, max_value=-1, max_row, max_column;

    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            cin >> get_num;
            if (get_num > max_value){
                max_value = get_num;
                max_row = i;
                max_column = j;
            }
        }
    }
    cout << max_value << '\n' << max_row << ' ' << max_column;
    return 0;
}