#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef struct Mouse_ {
    double J, F;
    double a;
}Mouse;

int n, m;
vector<Mouse> v;
vector<Mouse>::iterator it;
bool cmp(const Mouse m1, const Mouse m2) {
    if(m1.a != m2.a) {
        return m1.a > m2.a;
    } else {
        return m1.F < m2.F;
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        if (n == -1 && m == -1) {
            break;
        }
        Mouse mouse;
        v.clear();
        for (int i = 0; i < m; i ++) {
            scanf("%lf %lf", &mouse.J, &mouse.F);
            mouse.a = mouse.J / mouse.F;
            v.emplace_back(mouse);
        }
        sort(v.begin(), v.end(), cmp);
        double sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if(n > v[i].F) {
                sum += v[i].J;
                n-=v[i].F;
            } else {
                sum += n * v[i].a;
                break;
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}