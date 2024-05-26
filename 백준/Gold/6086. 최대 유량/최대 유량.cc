#include <bits/stdc++.h>
#define FOR(now,a,b) for(int now=(a);now<(b);now++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/6086

*/

#define MAX

struct MaximumFlow {
    struct Edge //정점과 용량을 정해줄 구조체 생성
    {
        int to;
        int capacity;
        Edge *reverse;
        Edge(int to, int capacity) :to(to), capacity(capacity) {};
    };

    int n;
    int source;
    int sink;
    vector<vector<Edge*>> graph;//Edge형 구조체의 2차원 벡터 생성
    MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink) 
    { graph.resize(n); };//간선의 정보가 주어졌을때 그만큼 벡터의 크기를 확장시켜줌

    void add_edge(int u, int v, int capacity)
    {
        Edge *ori = new Edge(v, capacity);
        Edge *reverse = new Edge(u, 0);//시작점
        ori->reverse = reverse;
        reverse->reverse = ori;
        graph[u].push_back(ori);
        graph[v].push_back(reverse);
    }
    int bfs()
    {
        vector <bool> check(n, false);
        vector <pair<int, int>> from(n, make_pair(-1, -1));
        queue <int> q;
        q.push(source);//시작점 푸쉬 후
        check[source] = true;//체크
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < graph[x].size(); i++)
            {
                int y = graph[x][i]->to;
                if (graph[x][i]->capacity > 0 && check[y] == 0)//용량이 0보다 크고 체크가 안되었다면
                {
                    q.push(y);
                    check[y] = true;
                    from[y] = make_pair(x, i);//정점 x와 i를 이어줌
                }
            }
        }
        //도착점이 체크가 안되었다면 이 그래프는 source와 sink가 연결이 안되어있음을 의미함
        if (check[sink] == 0)
        {
            return 0;//그러므로 종료
        }
        int s = sink;
        int c = graph[from[s].first][from[s].second]->capacity;
        while (from[s].first != -1)
        {
            if (c > graph[from[s].first][from[s].second]->capacity)
            {
                c = graph[from[s].first][from[s].second]->capacity;
            }
            s = from[s].first;
        }
        s = sink;
        while (from[s].first != -1)
        {
            Edge *e = graph[from[s].first][from[s].second];
            e->capacity -= c;//오는 방향은 -
            e->reverse->capacity += c;//가는 방향은 +
            s = from[s].first;
        }
        return c;
    }
    int flow()
    {
        int ans = 0;
        while (1)
        {
            int f = bfs();

            if (f == 0) { break; }
            ans += f;
        }
        return ans;
    }
};

int graph[52][52];

int changeAlphabet(char a){
    // 대소문자가 다르면 다른 문자
    if (a<='Z') return a-'A';
    else return a-'a'+26;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
    cin >> N;

	MaximumFlow mf(52, 0, 25);

    for(int i=0; i<N; i++){
        char from, to;
        int flow;
        cin >> from >> to >> flow;
        from = changeAlphabet(from);
        to = changeAlphabet(to);
        mf.add_edge(from, to, flow);
        mf.add_edge(to, from, flow);
    }

    cout << mf.flow();
    
    return 0;
}