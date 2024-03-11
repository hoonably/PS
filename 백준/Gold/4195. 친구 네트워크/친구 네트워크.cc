#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

/*
왜 출력초과가 나는가...
*/

unordered_map<string, string> parent;
unordered_map<string, int> cnt;  //부모에 따른 원소의 개수

// 부모 노드를 찾는 함수
string getParent(string s) {
    if (parent[s] == s) return s;
    return parent[s] = getParent(parent[s]);
}

// 작은 부모 노드의 값으로 초기화 (작은것을 항상 부모 노드로)
void unionParent(string a, string b) {
    string A = getParent(a);
    string B = getParent(b);

    // a==b인경우 둘 다 이미 같은 집합이므로 합치지 않음
    if (A == B) return;

    parent[B] = A;
    cnt[A] += cnt[B];
}

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