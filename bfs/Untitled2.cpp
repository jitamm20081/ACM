#include<iostream>
#include<algorithm>
using namespace std;
const int dx[5] = { -1,0,0,0,1 };
const int dy[5] = { 0,-1,0,1,0 };
int M, N;
int tile[20][20];
int opt[20][20];//保存最优解
int flip[20][20];//保存中间结果
//查询(x,y)的颜色
int get(int x, int y)
{
    int c = tile[x][y];
    for (int d = 0; d < 5; d++)
    {
        int x2 = x + dx[d], y2 = y + dy[d];
        if (x2 >= 0 && x2 < M&&y2 >= 0 && y2 < N)
            c += flip[x2][y2];//他前后左右被反转的总和和他自己本身的颜色的和
    }
    return c % 2;//对二取余即能确定他的颜色
}
int cal()
{
    for(int i=1;i<M;i++)//之前枚举第一行的状态了，所以从第二行开始
        for (int j = 0; j < N; j++)
        {
            if (get(i - 1, j) != 0)
                flip[i][j] = 1;//反转次数加1
        }
    for (int j = 0; j < N; j++)//检查最后一行是否存在仍不为白色的情况
        if (get(M - 1, j) != 0)
            return -1;
    int ans = 0;
    for (int i = 0; i < M; i++)//求反转次数的总和
        for (int j = 0; j < N; j++)
            ans += flip[i][j];
    return ans;
}
void solve()
{
    int ans = -1;
    for (int i = 0; i < 1 << N; i++)//进行2^N次循环
    {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < N; j++)//枚举第一行的所有反转情况
            flip[0][N - j - 1] = i >> j & 1;//以0000 0001 0010 0011这个规律
        int num = cal();
        if (num >= 0 && (ans < 0 || ans>num))
        {
            ans = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if (ans < 0)
        cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << opt[i][j] << (j + 1 == N ? '\n' : ' ');
            }
        }
    }
}
int main()
{
    while (cin >> M >> N)
    {
        memset(tile, 0, sizeof(tile));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> tile[i][j];
        solve();
    }
    return 0;
}
