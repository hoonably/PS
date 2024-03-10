#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

/*
중위 순회와 후위 순회가 주어졌을때 전위순회를 구하는 문제
inorder (중위 순회) : left Node -> root Node -> right Node
preorder (전위 순회) : root Node -> left Node -> right Node
postorder (후위 순회) : left Node -> right Node -> root Node

postorder의 마지막이 root Node 이기 때문에 rootNode를 먼저 알아낸 후
inorder에서 root의 위치를 찾아내고, 분할
postorder에서 inorder에서 분할되었던 부분을 찾아내 분할
*/

int n;
vector<int> inorder, postorder, Index;

// preorder 를 출력하는 함수 (재귀)
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    // 더 이상 분할 할 수 없는 경우 return
    if (inStart > inEnd || postStart > postEnd)
        return;
    // postorder의 끝 값이 root값
    // Index 배열을 통해 inorder에서의 root index를 쉽게 구할 수 있다.
    int rootIndex = Index[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    cout << inorder[rootIndex] << ' '; // root 값 출력

    // 재귀 함수 호출
    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    inorder.resize(n+1);
    postorder.resize(n+1);
    Index.resize(n+1);
    for (int i=1; i<=n; i++){
        cin >> inorder[i];
        Index[inorder[i]] = i; // inorder 요소들의 Index 정보 저장
    }
    for (int i=1; i<=n; i++){
        cin >> postorder[i];
    }
    getPreOrder(1, n, 1, n);
    
    return 0;
}