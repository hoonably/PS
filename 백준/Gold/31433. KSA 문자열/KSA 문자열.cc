#include <iostream>
using namespace std;
string X;
int answer = 10000000;
char KSA[] = {'K', 'S', 'A'};
void calc(string str, int cnt)
{
    int idx = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == KSA[idx % 3]) // 일치
        {
            ++idx;
        }
        else // 일치하지 않으니 제거
        {
            ++cnt;
        }
    }
    cnt += abs(static_cast<int>(idx - X.size()));
    answer = min(answer, cnt);
}
int main()
{
    cin >> X;

    calc(X, 0);
    calc("K" + X, 1);
    calc("KS" + X, 2);

    cout << answer;
    return 0;
}