#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 54
int maxDeep, n, mp[300], data[MX], opt[5][2],
chgs[6][9] = {
    9, 10, 11, 23, 35, 34, 33, 21, 22,
    12, 13, 14, 26, 38, 37, 36, 24, 25,
    15, 16, 17, 29, 41, 40, 39, 27, 28,
    18, 19, 20, 32, 44, 43, 42, 30, 31,
    0, 1, 2, 5, 8, 7, 6, 3, 4,
    45, 46, 47, 50, 53, 52, 51, 48, 49
}, chge[6][12] = {
    44, 32, 20, 0, 3, 6, 12, 24, 36, 45, 48, 51,
    35, 23, 11, 6, 7, 8, 15, 27, 39, 47, 46, 45,
    38, 26, 14, 8, 5, 2, 18, 30, 42, 53, 50, 47,
    41, 29, 17, 2, 1, 0, 9, 21, 33, 51, 52, 53,
    11, 10, 9, 20, 19, 18, 17, 16, 15, 14, 13, 12,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44
};
int vle() {
    int rtn = 0, i, j, tmp[6], siz;
    for (i = 0; i < 6; ++i) {
        memset(tmp, 0, sizeof tmp); siz = -1;
        for (j = 0; j < 9; ++j) ++tmp[data[chgs[i][j]]];
        for (j = 0; j < 6; ++j) if (tmp[j]) ++siz;
        rtn = std::max(rtn, siz>3 ? 3 : siz);
    }
    return rtn;
}
void chg(int n, int drc) {
    int i, tmpe[15], tmps[15];
    if (~drc) {
        memcpy(tmpe + 3, chge[n], sizeof chge[n]); memcpy(tmps + 2, chgs[n], sizeof chgs[n]);
        memcpy(tmpe, tmpe + 12, sizeof(int)* 3); memcpy(tmps, tmps + 8, sizeof(int)* 2);
    }
    else {
        memcpy(tmpe, &chge[n][3], sizeof(int)* 9); memcpy(tmps, &chgs[n][2], sizeof(int)* 6);
        memcpy(tmpe + 9, chge[n], sizeof(int)* 3); memcpy(tmps + 6, chgs[n], sizeof(int)* 2);
    }
    for (i = 0; i < 12; ++i) tmpe[i] = data[tmpe[i]];
    for (i = 0; i < 12; ++i) data[chge[n][i]] = tmpe[i];
    for (i = 0; i < 8; ++i) tmps[i] = data[tmps[i]];
    for (i = 0; i < 8; ++i) data[chgs[n][i]] = tmps[i];
}

bool DFS(int deep) {
    int i = vle();
    if (i + deep>maxDeep) return 0;
    if (!i) return 1;
    for (i = 0; i < 6; ++i) {
        chg(opt[deep][0] = i, opt[deep][1] = 1);
        if (DFS(deep + 1)) return 1;
        chg(i, -1);
        chg(opt[deep][0] = i, opt[deep][1] = -1);
        if (DFS(deep + 1)) return 1;
        chg(i, 1);
    }
    return 0;
}

int main() {
    mp['w'] = 0; mp['r'] = 1; mp['g'] = 2; mp['b'] = 3; mp['o'] = 4; mp['y'] = 5;
    int t, i;
    char c;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < MX; ++i) {
            scanf(" %c", &c); data[i] = mp[c];
        }
        for (maxDeep = vle(); maxDeep < 6 && !DFS(0); ++maxDeep);
        if (maxDeep < 6) {
            printf("%d\n", maxDeep);
            for (i = 0; i < maxDeep; ++i) printf("%d %d\n", opt[i][0], opt[i][1]);
        }
        else puts("-1");
    }
    return 0;
}