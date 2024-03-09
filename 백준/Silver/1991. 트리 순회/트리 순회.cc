#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int N;
pair<char,char> node[26];

// 전위 순회
void preorder(char cur){
    if(cur=='.')
    return;
    
    cout << cur;
    preorder(node[cur-'A'].first);
    preorder(node[cur-'A'].second);
}
// 중위순회
void inorder(char cur){
    if(cur=='.')
    return;

    inorder(node[cur-'A'].first);
    cout << cur;
    inorder(node[cur-'A'].second);
}
// 후위순회
void postorder(char cur){
    if(cur=='.')
    return;

    postorder(node[cur-'A'].first);
    postorder(node[cur-'A'].second);
    cout << cur;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        node[parent-'A'].first = left;
        node[parent-'A'].second = right;
    }

    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
}