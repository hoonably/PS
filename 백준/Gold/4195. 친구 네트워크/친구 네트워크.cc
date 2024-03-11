#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX

/*

*/

unordered_map<string, string> parent;
unordered_map<string, int> cnt;  //부모에 따른 원소의 개수

// 부모 노드를 찾는 함수
string getParent(string s) {
    if (parent[s] == s) return s;
    return parent[s] = getParent(parent[s]);
}

void unionParent(string a, string b) {
    a = getParent(a);
    b = getParent(b);

    // a==b인 경우 둘이 이미 같은 집합이므로 합치지 않음
    if (a == b) return;

    parent[b] = a;
    cnt[a] += cnt[b];
}

// 여기서 실수로 void가 아닌 int로 썼는데 출력초과가 나옴.
// (void로 바꾸기만 하면 맞음)
// int로 함수를 썼을 경우 출력에 무슨 영향이 있는가?

void solve(){
    int F;
    cin >> F;
    for(int i=0; i<F; i++){
        string a, b;
        cin >> a >> b;
        // 처음 나옴 이름이라면 추가
        if (parent.find(a)==parent.end()){
            parent[a] = a;
            cnt[a] = 1;
        }
        if (parent.find(b)==parent.end()){
            parent[b] = b;
            cnt[b] = 1;
        }
        unionParent(a, b);
        cout << cnt[getParent(a)] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        parent.clear();
        cnt.clear();
        solve();
    }

    return 0;
}