#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double INF = numeric_limits<double>::infinity();

class LPSolver {
public:
    LPSolver(const vector<vector<double>>& a, const vector<double>& b, const vector<double>& c)
        : m(b.size()), N(c.size()), container_n(N + 1), container_b(m), container_d(m + 2, vector<double>(N + 2)) {
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < N; ++j) {
                container_d[i][j] = a[i][j];
            }
        }

        for (size_t i = 0; i < m; ++i) {
            container_b[i] = N + i;
            container_d[i][N] = -1.0;
            container_d[i][N + 1] = b[i];
        }

        for (size_t j = 0; j < N; ++j) {
            container_n[j] = j;
            container_d[m][j] = -c[j];
        }

        container_n[N] = -1;
        container_d[m + 1][N] = 1.0;
    }

    void pivot(size_t r, size_t s) {
        double inv = 1.0 / container_d[r][s];
        for (size_t i = 0; i < m + 2; ++i) {
            if (i != r && fabs(container_d[i][s]) > EPS) {
                double inv2 = container_d[i][s] * inv;
                for (size_t j = 0; j < N + 2; ++j) {
                    container_d[i][j] -= container_d[r][j] * inv2;
                }
                container_d[i][s] = container_d[r][s] * inv2;
            }
        }

        for (size_t j = 0; j < N + 2; ++j) {
            if (j != s) {
                container_d[r][j] *= inv;
            }
        }

        for (size_t i = 0; i < m + 2; ++i) {
            if (i != r) {
                container_d[i][s] *= -inv;
            }
        }

        container_d[r][s] = inv;
        swap(container_b[r], container_n[s]);
    }

    bool simplex(int phase) {
        size_t x = m + phase - 1;

        while (true) {
            int s = -1;
            for (size_t j = 0; j <= N; ++j) {
                if (container_n[j] != -phase) {
                    if (s == -1 || make_pair(container_d[x][j], container_n[j]) < make_pair(container_d[x][s], container_n[s])) {
                        s = j;
                    }
                }
            }

            if (container_d[x][s] >= -EPS) {
                return true;
            }

            int r = -1;
            for (size_t i = 0; i < m; ++i) {
                if (container_d[i][s] <= EPS) {
                    continue;
                }
                if (r == -1 || make_pair(container_d[i][N + 1] / container_d[i][s], container_b[i]) < make_pair(container_d[r][N + 1] / container_d[r][s], container_b[r])) {
                    r = i;
                }
            }

            if (r == -1) {
                return false;
            }

            pivot(r, s);
        }
    }

    double solve(vector<double>& x) {
        size_t r = 0;
        for (size_t i = 1; i < m; ++i) {
            if (container_d[i][N + 1] < container_d[r][N + 1]) {
                r = i;
            }
        }

        if (container_d[r][N + 1] < -EPS) {
            pivot(r, N);
            if (!simplex(2) || container_d[m + 1][N + 1] < -EPS) {
                return -INF;
            }

            for (size_t i = 0; i < m; ++i) {
                if (container_b[i] == -1) {
                    int s = -1;
                    for (size_t j = 0; j <= N; ++j) {
                        if (container_n[j] != -1) {
                            if (s == -1 || make_pair(container_d[i][j], container_n[j]) < make_pair(container_d[i][s], container_n[s])) {
                                s = j;
                            }
                        }
                    }
                    pivot(i, s);
                }
            }
        }

        if (simplex(1)) {
            for (size_t i = 0; i < m; ++i) {
                if (container_b[i] < static_cast<int>(N)) {
                    x[container_b[i]] = container_d[i][N + 1];
                }
            }
            return container_d[m][N + 1];
        }

        return INF;
    }

private:
    size_t m, N;
    vector<int> container_n, container_b;
    vector<vector<double>> container_d;
};

struct dot{int x, y;};
double getDist(dot a, dot b){
    int dx = a.x-b.x;
    int dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

dot A[201];
double dists[201][201];
double distsMin[201];  // 각 점에서 최소거리

int main() {

    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int x, y;
        cin >> A[i].x >> A[i].y;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            double dist = getDist(A[i], A[j]);
            dists[i][j] = dist;
            dists[j][i] = dist;
        }
    }

    // 각 점에서 가능한 최대 반지름 기록
    fill(distsMin, distsMin+201, 1e9);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            distsMin[i] = min(distsMin[i], dists[i][j]);
            distsMin[j] = min(distsMin[j], dists[i][j]);
        }
    }

    vector<vector<double>> a(N * (N - 1) / 2, vector<double>(N));
    vector<double> b(N * (N - 1) / 2);
    vector<double> c(N, 1.0);
    int idx = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (distsMin[i] + distsMin[j] <= dists[i][j] + EPS) {
                continue;
            }
            a[idx][i] = 1.0;
            a[idx][j] = 1.0;
            b[idx] = dists[i][j];
            ++idx;
        }
    }

    vector<double> ret(N * (N - 1) / 2);
    LPSolver solver(a, b, c);
    solver.solve(ret);

    double ans = 0;
    for (double i : ret){
        ans += i;
    }
    printf("%.6f\n", 2.0 * M_PI * ans);

    return 0;
}