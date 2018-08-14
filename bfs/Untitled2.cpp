#include<iostream>
#include<algorithm>
using namespace std;
const int dx[5] = { -1,0,0,0,1 };
const int dy[5] = { 0,-1,0,1,0 };
int M, N;
int tile[20][20];
int opt[20][20];//�������Ž�
int flip[20][20];//�����м���
//��ѯ(x,y)����ɫ
int get(int x, int y)
{
    int c = tile[x][y];
    for (int d = 0; d < 5; d++)
    {
        int x2 = x + dx[d], y2 = y + dy[d];
        if (x2 >= 0 && x2 < M&&y2 >= 0 && y2 < N)
            c += flip[x2][y2];//��ǰ�����ұ���ת���ܺͺ����Լ��������ɫ�ĺ�
    }
    return c % 2;//�Զ�ȡ�༴��ȷ��������ɫ
}
int cal()
{
    for(int i=1;i<M;i++)//֮ǰö�ٵ�һ�е�״̬�ˣ����Դӵڶ��п�ʼ
        for (int j = 0; j < N; j++)
        {
            if (get(i - 1, j) != 0)
                flip[i][j] = 1;//��ת������1
        }
    for (int j = 0; j < N; j++)//������һ���Ƿ�����Բ�Ϊ��ɫ�����
        if (get(M - 1, j) != 0)
            return -1;
    int ans = 0;
    for (int i = 0; i < M; i++)//��ת�������ܺ�
        for (int j = 0; j < N; j++)
            ans += flip[i][j];
    return ans;
}
void solve()
{
    int ans = -1;
    for (int i = 0; i < 1 << N; i++)//����2^N��ѭ��
    {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < N; j++)//ö�ٵ�һ�е����з�ת���
            flip[0][N - j - 1] = i >> j & 1;//��0000 0001 0010 0011�������
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
