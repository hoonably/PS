#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 


//    -    0
//   | |  1  2 
//    -    3
//   | |  4  5
//    -    6

// 각 숫자마다 위의 칸에 무엇이 있는지
char change[10][7] = {
    {'-', '|', '|', ' ', '|', '|', '-'},  // 0
    {' ', ' ', '|', ' ', ' ', '|', ' '},  // 1
    {'-', ' ', '|', '-', '|', ' ', '-'},  // 2
    {'-', ' ', '|', '-', ' ', '|', '-'},  // 3
    {' ', '|', '|', '-', ' ', '|', ' '},  // 4
    {'-', '|', ' ', '-', ' ', '|', '-'},  // 5
    {'-', '|', ' ', '-', '|', '|', '-'},  // 6
    {'-', ' ', '|', ' ', ' ', '|', ' '},  // 7
    {'-', '|', '|', '-', '|', '|', '-'},  // 8
    {'-', '|', '|', '-', ' ', '|', '-'},  // 9
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int s;
    string n;
    cin >> s >> n;
    
    // 0단계
    for(int num : n){
        cout << ' ';
        for(int i=0; i<s; i++) cout << change[num-'0'][0];
        cout << "  ";
    }
    cout << '\n';

    // 1, 2단계
    for(int i=0; i<s; i++){
        for(int num : n){
            cout << change[num-'0'][1];
            for(int i=0; i<s; i++) cout << ' ';
            cout << change[num-'0'][2];
            cout << ' ';
        }
        cout << '\n';
    }

    // 3단계
    for(int num : n){
        cout << ' ';
        for(int i=0; i<s; i++) cout << change[num-'0'][3];
        cout << "  ";
    }
    cout << '\n';

    // 4, 5단계
    for(int i=0; i<s; i++){
        for(int num : n){
            cout << change[num-'0'][4];
            for(int i=0; i<s; i++) cout << ' ';
            cout << change[num-'0'][5];
            cout << ' ';
        }
        cout << '\n';
    }

    // 6단계
    for(int num : n){
        cout << ' ';
        for(int i=0; i<s; i++) cout << change[num-'0'][6];
        cout << "  ";
    }
    cout << '\n';
    
    return 0;
}