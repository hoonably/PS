#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*
inorder (중위 순회) : left Node -> root Node -> right Node
preorder (전위 순회) : root Node -> left Node -> right Node
postorder (후위 순회) : left Node -> right Node -> root Node

이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램

EOF 테스트 입력 방법
ctrl + D 입력시 eof가 입력됨
*/

vector<int> preorder;

void getPostOrder(int start, int end){
    // 범위가 없으면
    if (start > end-1) return;

    // 범위가 1개라면
    if (start == end-1){
        cout << preorder[start] << '\n';
        return;
    }

    // root보다 큰 값이 나오는 순간부터 right node
    int root = preorder[start];
    int idx = start+1;
    while (idx < end){
        if (preorder[idx]>root) break;
        idx++;
    }
    getPostOrder(start+1, idx);
    getPostOrder(idx, end);
    cout << preorder[start] << '\n';  // root를 가장 나중에 출력
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int num;
    while(cin >> num){  // EOF : ctrl+D
        preorder.push_back(num);
    }
    
    getPostOrder(0, preorder.size());

    return 0;
}