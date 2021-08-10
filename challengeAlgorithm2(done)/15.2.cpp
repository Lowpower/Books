#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;
static const int MAX = 100000;
static const int INFTY = (1 << 29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

int main() {
    int s, t, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        V[i] = false;
    }
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }
    return 0;
}