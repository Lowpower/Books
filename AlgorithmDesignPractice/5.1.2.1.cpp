#include <iostream>
#include <cstring>

using namespace std;
int map[105][105];

int main() {
    int t, max_x, max_y, sum_s, n, k, x1, y1, x2, y2;
    scanf("%d",&t);
    while(t--) {
        memset(map, 0, sizeof(map));
        max_x = 0;
        max_y = 0;
        sum_s = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <=n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(x1 > max_x) {
                max_x = x1;
            }
            if(x2 > max_x) {
                max_x = x2;
            }
            if(y1 > max_y) {
                max_y = y1;
            }
            if(x1 < x2) {
                for(int j = x1; j<=x2; j++) {
                    map[j][y1] = i;
                }
            } else {
                for(int j = x2; j<= x2; j++){
                    map[j][y1] = i;
                }
            }
        }
        for (int i = 0; i <= max_x; i++){
            int tem = 0;
            for(int j = 0; j <= max_y; j++) {
                if(map[i][j] >0) {
                    tem++;
                }
                int offset = tem - k;
                if(offset > 0) {
                    sum_s += offset;
                    while(offset--) {
                        int max_s = 0, max_bh;
                        for(int k = 0; k <= max_y; k++) {
                            if(map[i][k] >0) {
                                int tem_s = 0;
                                for(int z = i+1; z<=max_x; z++) {
                                    if(map[z][k] == map[i][k]) {
                                        tem_s++;
                                    } else {
                                        break;
                                    }
                                }
                                if(max_s < tem_s) {
                                    max_x = tem_s;
                                    max_bh = k;
                                }
                            }
                        }
                        for(int a = i; a < i+max_s; a++) {
                            map[a][max_bh] = 0;
                        }
                    }
                }
            }
        }
        printf("%d\n", sum_s);
    }
    return 0;
}