#include<iostream>
   
#define MAX 9
using namespace std;
   
int sudoku[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];
   
void print_sudoku() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << '\n';
    }
}
   
void DFS(int depth){

    int x = depth / MAX;    // x 좌표
    int y = depth % MAX;    // y 좌표
   
    if (depth == MAX*MAX) {
        print_sudoku();
        exit(0);
    }

   
    // 이미 채워져있다면
    if (sudoku[x][y] != 0) {
        DFS(depth + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (Row[x][i] || Col[y][i] || Square[(x/3) * 3 + (y/3)][i]) continue;

        sudoku[x][y] = i;
        Row[x][i] = true;
        Col[y][i] = true;
        Square[(x / 3) * 3 + (y / 3)][i] = true;
        
        DFS(depth + 1);

        sudoku[x][y] = 0;
        Row[x][i] = false;
        Col[y][i] = false;
        Square[(x / 3) * 3 + (y / 3)][i] = false;
    }

}
   
   
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) continue;

            Row[i][sudoku[i][j]] = true;
            Col[j][sudoku[i][j]] = true;
            Square[(i/3)*3 + (j/3)][sudoku[i][j]] = true;
        }
    }
    DFS(0);
   
    return 0;
}