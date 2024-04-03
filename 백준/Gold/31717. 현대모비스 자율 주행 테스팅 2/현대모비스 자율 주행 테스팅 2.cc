#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 200001

/*

*/

int M, K;
// track[a][b][c] : a번 라인 b번 트랙 c는 거리
vector<string> track[2];
vector<int> order;
bool lineChange[MAX];  // 마지막이 하나인지

// 각 트랙별 시작과 끝 위치에 따른 시간 구하기

// times[출발지점][트랙번호] = {도착지점, 걸린 시간}
pair<int,int> times[2][MAX];
bool able[2][MAX];  // K번트랙이 0또는 1번 레인에서 시작해 막히지 않고 완주할 수 있는지

bool go(int line, int trackNum){

    // 출발 불가능
    if (track[line][trackNum][0]=='#') return false;

    int startLine = line;

    // 트랙의 마지막 인덱스
    int lastIdx = track[0][trackNum].length()-1;

    int cnt = 0;
    for (int idx=1; idx<=lastIdx; idx++){

        // 못감
        if (track[0][trackNum][idx]=='#' && track[1][trackNum][idx]=='#')
            return false;

        // 대각선으로 막혀있어서 못감
        if (track[line^1][trackNum][idx-1]=='#' && track[line][trackNum][idx]=='#') 
            return false;

        // 차선변경
        if (track[line][trackNum][idx]=='#'){
            line ^= 1;
            cnt++;
        }
        // 전진
        cnt++;
    }

    // 마지막에 두개의 경로라서 차선 변경이 가능한지
    if (track[line^1][trackNum][lastIdx]=='.'){
        lineChange[trackNum] = true;
    }

    // times[출발지점][트랙번호] = {도착지점, 걸린 시간}
    times[startLine][trackNum] = {line, cnt};

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    

    cin >> M >> K;

    for (int i=0; i<K; i++){
        int num;
        cin >> num;
        order.push_back(num-1);
    }

    // 총 트랙 개수
    track[0].resize(M);
    track[1].resize(M);

    // 트랙 받기 (string) 사용
    // track[a][b][c] : a번 라인 b번 트랙 c는 거리
    for (int i=0; i<M; i++){
        cin >> track[0][i];
        cin >> track[1][i];
    }

    for (int t=0; t<M; t++){
        // 0에서 출발
        if (go(0, t)) able[0][t] = true;

        // 1에서 출발
        if (go(1, t)) able[1][t] = true;
    }

    // for (int t=0; t<M; t++){
    //     cout << '\n' << t << " 번 트랙\n";
    //     if (able[0][t])
    //         cout << "0 -> " << times[0][t].first << " : " << times[0][t].second << "초 걸림\n";
    //     if (able[1][t])
    //         cout << "1 -> " << times[1][t].first << " : " << times[1][t].second << "초 걸림\n";
    // }

    // 0에서 출발
    bool start0 = true;
    int line = 0;
    ll cnt0 = K-1;  // 트랙끼리 이동하는데 필수로 드는 시간

    // 출발 못함
    if (track[0][order[0]][0]=='#'){
        start0 = false;
    }
    else{

        // 마지막에 옆에 없어서 라인 변경을 할 수 있는지
        bool lc = true;

        for (int trackNum : order){
            // 라인 그대로 가는게 가능하다면
            if (able[line][trackNum]) {
                cnt0 += times[line][trackNum].second;
                line = times[line][trackNum].first;
            }
            // 라인 변경하면 갈 수 있다면
            else if (able[line^1][trackNum] && lc) {
                cnt0++;  // 라인 변경
                cnt0 += times[line^1][trackNum].second;
                line = times[line^1][trackNum].first;
            }
            
            // 못간다면
            else {
                start0 = false;
                break;
            }

            // 옆에 장애물이 없어 다음에 라인체인지가 가능한지
            lc = lineChange[trackNum];
        }
    }


    // 1에서 출발
    bool start1 = true;
    line = 1;
    ll cnt1 = K-1;

    // 출발 못함
    if (track[1][order[0]][0]=='#'){
        start1 = false;
    }
    else{
        // 마지막에 옆에 없어서 라인 변경을 할 수 있는지
        bool lc = true;

        for (int trackNum : order){
            // 라인 그대로 가는게 가능하다면
            if (able[line][trackNum]) {
                cnt1 += times[line][trackNum].second;
                line = times[line][trackNum].first;
            }
            // 라인 변경하면 갈 수 있다면
            else if (able[line^1][trackNum] && lc) {
                cnt1++;  // 라인 변경 비용
                cnt1 += times[line^1][trackNum].second;
                line = times[line^1][trackNum].first;
            }
            // 못간다면
            else {
                start1 = false;
                break;
            }
            // 옆에 장애물이 없어 다음에 라인체인지가 가능한지
            lc = lineChange[trackNum];
        }
    }


    if (start0 == false && start1 == false){
        cout << "-1";
    }
    else if (start0 == false){
        cout << cnt1;
    }
    else if (start1 == false){
        cout << cnt0;
    }
    else {
        cout << min(cnt0, cnt1);
    }
    
    return 0;
}