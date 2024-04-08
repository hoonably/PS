#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 101

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기
+ // (Px, Py)가 볼록 다각형 안에 있는지 판단
*/

struct dot { long long x, y; };
dot operator-(dot A, dot B) {
    dot C;
    C.x = A.x - B.x, C.y = A.y - B.y;
    return C;
}
vector<dot> Black, White;

long long Cross(dot A, dot B, dot C) {
    dot AB = B-A;
    dot AC = C-A;
    return AB.x*AC.y - AB.y*AC.x;
}

bool CrossCompBlack(dot A, dot B) {
    long long Value = Cross(Black[0], A, B);
    if(Value != 0) return Value > 0;
    else if(A.y != B.y) return A.y < B.y;
    else return A.x < B.x;
}

bool CrossCompWhite(dot A, dot B) {
    long long Value = Cross(White[0], A, B);
    if(Value != 0) return Value > 0;
    else if(A.y != B.y) return A.y < B.y;
    else return A.x < B.x;
}

bool isInPoly(vector<dot> &Poly, dot P) {
    int Size = Poly.size();
    dot Origin; Origin.x = 0, Origin.y = 0;
    dot LeftV = Poly[Size-1] - Poly[0];
    dot RightV = Poly[1] - Poly[0];
    dot PointV = P - Poly[0];
    if(Cross(Origin, LeftV, PointV) > 0) return false;
    if(Cross(Origin, RightV, PointV) < 0) return false;

    int Left = 1, Right = Size - 1;
    while(Left+1 < Right) {
        int Mid = (Left + Right)/2;
        dot MidV = Poly[Mid] - Poly[0];
        if(Cross(Origin, MidV, PointV) > 0) Left = Mid;
        else Right = Mid;
    }
    dot V1 = P - Poly[Left];
    dot V2 = Poly[Left+1] - P;
    return Cross(Origin, V1, V2) <= 0;
}

bool solve(){
    int N, M;
    cin >> N >> M;
    Black.resize(N), White.resize(M);
    for(int i=0; i<N; i++) cin >> Black[i].x >> Black[i].y;
    for(int i=0; i<M; i++) cin >> White[i].x >> White[i].y;

    if(N == 0 || M == 0) {
        return true;
    }
    else if(N <= 2 && M <= 2) {
        dot A, B, C, D;
        A = B = Black[0], C = D = White[0];
        if(N == 2) B = Black[1];
        if(M == 2) D = White[1];
        long long AB = Cross(A, B, C) * Cross(A, B, D);
        long long CD = Cross(C, D, A) * Cross(C, D, B);
        if(AB == 0 && CD == 0) {
            if(A.x > B.x || (A.x == B.x && A.y > B.y)) swap(A, B);
            if(C.x > D.x || (C.x == D.x && C.y > D.y)) swap(C, D);
            if((C.x < B.x || (C.x == B.x && C.y <= B.y))
                && (A.x < D.x || (A.x == D.x && A.y <= D.y))) return false;
            else return true;
        }
        else {
            if(AB <= 0 && CD <= 0) return false;
            else return true;
        }
    }

    for(int i=1; i<N; i++) {
        if(Black[i].y < Black[0].y || (Black[i].y == Black[0].y && Black[i].x < Black[0].x)) {
            swap(Black[0], Black[i]);
        }
    }
    sort(Black.begin()+1, Black.end(), CrossCompBlack);
    vector<dot> PolyBlack;
    PolyBlack.push_back(Black[0]);
    PolyBlack.push_back(Black[1]);
    for(int i=2; i<N; i++) {
        while(PolyBlack.size() >= 2) {
            dot temp2 = PolyBlack.back();
            PolyBlack.pop_back();
            dot temp1 = PolyBlack.back();
            if(Cross(temp1, temp2, Black[i]) > 0) {
                PolyBlack.push_back(temp2);
                break;
            }
        }
        PolyBlack.push_back(Black[i]);
    }

    for(int i=1; i<M; i++) {
        if(White[i].y < White[0].y || (White[i].y == White[0].y && White[i].x < White[0].x)) {
            swap(White[0], White[i]);
        }
    }

    sort(White.begin()+1, White.end(), CrossCompWhite);
    vector<dot> PolyWhite;
    PolyWhite.push_back(White[0]);
    PolyWhite.push_back(White[1]);
    for(int i=2; i<M; i++) {
        while(PolyWhite.size() >= 2) {
            dot temp2 = PolyWhite.back();
            PolyWhite.pop_back();
            dot temp1 = PolyWhite.back();
            if(Cross(temp1, temp2, White[i]) > 0) {
                PolyWhite.push_back(temp2);
                break;
            }
        }
        PolyWhite.push_back(White[i]);
    }

    if(N >= 3) {
        for(int i=0; i<M; i++)
            if(isInPoly(PolyBlack, White[i])) return false;
    }
    if(M >= 3) {
        for(int i=0; i<N; i++)
            if(isInPoly(PolyWhite, Black[i])) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}