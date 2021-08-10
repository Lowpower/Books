#include <iostream>
#include <cstring>

using namespace std;
const int MX = 50;
int map[MX][MX];
int x[MX];
int ssum = 0;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    cout << "input:" << endl;
    int u, v, edge;
    cin >> edge;
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= edge; i++)
    {
        cin >> u >> v;
        map[u][v] = map[v][u] = 1;
    }
    int sum = 0;
    auto Backtrack = [&](int t) {
        if (t > n) {
            sum++;
            cout << "sum:" << sum << "  :";
            for (int i = 1; i <= m; i++)
            {
                cout << x[i] << "    ";
            }
            cout << endl;
        } else {
            if() {}
        }
    };
    return 0;
}