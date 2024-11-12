#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

struct ch{
    char c;
    ch* prev;
    ch* next;
    ch(char _c) : c(_c), prev(nullptr), next(nullptr){}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str; cin >> str;

    ch* header = new ch('\0');
    ch* trailer = new ch('\0');
    ch* now = header;

    header->next = trailer;
    trailer->prev = header;

    for(char c : str){
        ch* next = new ch(c);
        now->next = next;
        next->prev = now;
        now = next;
    }
    now->next = trailer;
    trailer->prev = now;
    now = trailer;

    int M; cin >> M;
    while(M--){
        char op; cin >> op;
        if (op == 'L'){
            if (now->prev != header) now = now->prev;
        }
        else if (op == 'D'){
            if (now->next != nullptr) now = now->next;
        }
        else if (op == 'B'){
            if (now->prev != header) {
                ch* to_delete = now->prev;
                to_delete->prev->next = now;
                now->prev = to_delete->prev;
                delete to_delete;
            }
        }
        else {  // P
            cin >> op;
            ch* next = new ch(op);
            next->next = now;
            next->prev = now->prev;
            now->prev->next = next;
            now->prev = next;
        }
    }
    now = header->next;
    while(now != trailer){
        cout << now->c;
        now = now->next;
    }

    return 0;
}