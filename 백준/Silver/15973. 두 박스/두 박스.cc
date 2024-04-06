#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX
#define y1 notUsed

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int x1, y1, x2, y2, _x1, _y1, _x2, _y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> _x1 >> _y1 >> _x2 >> _y2;
    if(x1 > _x1){
        swap(x1, _x1);
        swap(y1, _y1);
        swap(x2, _x2);
        swap(y2, _y2);
    }
    if(x2 == _x1){
        if(y2 == _y1 || y1 == _y2){
            cout << "POINT" << "\n";
        }else cout <<"LINE" << "\n";
        //겹치거나. 
    }else if(x2 > _x1){
        //아예 박으로 나가거나. 
        if(y2 < _y1 || y1 > _y2) cout << "NULL" << "\n"; 
        else if(y2 == _y1 || y1 == _y2) cout << "LINE" << "\n"; 
        else cout << "FACE" << "\n";
    }else if(x2 < _x1) cout << "NULL" << "\n"; 


    return 0;
}