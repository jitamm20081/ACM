/*************************************************************************
	> File Name: Eight_3.cpp
	> Author: Zhanghaoran
	> Mail: chilumanxi@xiyoulinux.org
	> Created Time: Sun 11 Oct 2015 01:14:22 PM CST
 ************************************************************************/
 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
 
using namespace std;
const int INF = 0x3f3f3f3f;
struct Node{
    int a, b;
    Node(int x = 0, int y = 0){
        a = x;
        b = y;
    }
};
int T;
const int di[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const char dir[4] = {'d', 'l', 'r', 'u'};
bool ok;
int Map[3][3];
Node f[11];
int ans[300];
int Limit;
int nowx, nowy;
 
int get_h(){
    int temp = 0;
    for(int i = 0; i < 9; i ++){
        int x = i / 3;
        int y = i % 3;
        if(Map[x][y] == 0)
            continue;
        temp += abs(x - f[Map[x][y]].a) + abs(y - f[Map[x][y]].b);
    }
    return temp;
}
bool check(int x, int y){
    if(x >= 0 && x < 3 && y < 3 && y >= 0)
        return true;
    else 
        return false;
}
int IDA(int x, int y, int p, int cur){
    int r = INF;
    int temp;
    int h = get_h();
    if(cur + h > Limit)
        return cur + h;
    if(h == 0){
        ok = true;
        return cur;
    }
    for(int i = 0; i < 4; i ++){
        if(i == p)
            continue;
        int tx = x + di[i][0];
        int ty = y + di[i][1];
        if(!check(tx, ty))
            continue;
        swap(Map[x][y], Map[tx][ty]);
        ans[cur] = i;
        int lr = IDA(tx, ty, 3 - i, cur + 1);
        if(ok)
            return lr;
        r = min(r, lr);
        swap(Map[x][y], Map[tx][ty]);
    }
    return r;
}
 
int main(void){
    int N = 1;
    char ch;
    cin >> T;
    getchar();
    while(T --){
        for(int i = 0; i < 9; i ++){
            ch = getchar();
            if(ch == 'X' || ch == 'x'){
                nowx = i / 3;
                nowy = i % 3;
                Map[nowx][nowy] = 0;
            }
            if(ch <= '9' && ch >= '0')
                Map[i / 3][i % 3] = ch - '0';
        }
        getchar();
        for(int i = 0; i < 9; i ++){
            ch =  getchar();
            if(ch == 'X' || ch == 'x')
                continue;
            else if(ch <= '9' && ch >= '0')
                f[ch - '0'] = Node(i / 3, i % 3);
        }
        getchar();
        Limit = get_h();
        ok = false;
        while(!ok)
            Limit = IDA(nowx, nowy, -10, 0);
        printf("Case %d: %d\n",N++,Limit);
        for(int i = 0; i < Limit; i ++)
            putchar(dir[ans[i]]);
        puts("");
    }
    return 0;
}

