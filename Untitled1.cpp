#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>
 
using namespace std;
 
#define LL long long
const int INF = 0x3f3f3f3f;
const int maxn = 300005;
 
int n, m, a[20][20], tot, p[1000][3];
char ch[100];
 
struct DLX
{
	int L[maxn], R[maxn], U[maxn], D[maxn];
	int row[maxn], col[maxn], ans[maxn], sum[maxn];
	int n, m, num, cnt;
	void add(int k, int l, int r, int u, int d, int x, int y)
	{
		L[k] = l;   R[k] = r;   U[k] = u;
		D[k] = d;   row[k] = x;  col[k] = y;
	}
	void reset(int n, int m)
	{
		this->n = n;   this->m = m;
		for (int i = 0; i <= m; i++)
		{
			add(i, i - 1, i + 1, i, i, 0, i);
			sum[i] = 0;
		}
		L[0] = m, R[m] = 0, cnt = m + 1;
	}
	void insert(int x, int y)
	{
		int temp = cnt - 1;
		if (row[temp] != x)
		{
			add(cnt, cnt, cnt, U[y], y, x, y);
			U[D[cnt]] = cnt; D[U[cnt]] = cnt;
		}
		else
		{
			add(cnt, temp, R[temp], U[y], y, x, y);
			R[L[cnt]] = cnt; L[R[cnt]] = cnt;
			U[D[cnt]] = cnt; D[U[cnt]] = cnt;
		}
		sum[y]++, cnt++;
	}
	void remove(int k)
	{
		R[L[k]] = R[k], L[R[k]] = L[k];
		for (int i = D[k]; i != k; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				D[U[j]] = D[j];
				U[D[j]] = U[j];
				sum[col[j]]--;
			}
	}
	void resume(int k)
	{
		R[L[k]] = k, L[R[k]] = k;
		for (int i = D[k]; i != k; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				D[U[j]] = j;
				U[D[j]] = j;
				sum[col[j]]++;
			}
	}
	bool dfs(int k)
	{
		if (!R[0]) { num = k; return true; }
		int now = R[0];
		for (int i = now; i != 0; i = R[i])
			if (sum[now] > sum[i]) now = i;
		remove(now);
		for (int i = D[now]; i != now; i = D[i])
		{
			ans[k] = row[i];
			for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
			if (dfs(k + 1)) return true;
			for (int j = L[i]; j != i; j = L[j]) resume(col[j]);
		}
		resume(now);
		return false;
	}
	void display()
	{
		for (int i = 0; i < num; i++)
			a[p[ans[i]][0]][p[ans[i]][1]] = p[ans[i]][2];
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) printf("%d", a[i][j]);
		printf("\n");
	}
}dlx;
 
void insert(int x, int y, int z)
{
	p[++tot][0] = x;
	p[tot][1] = y;
	p[tot][2] = z;
	dlx.insert(tot, 9 * (x - 1) + y);
	dlx.insert(tot, 81 + 9 * (x - 1) + z);
	dlx.insert(tot, 162 + 9 * (y - 1) + z);
	x = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
	dlx.insert(tot, 243 + 9 * (x - 1) + z);
}
 
int main()
{
	while (~scanf("%s", ch + 1) && strcmp(ch + 1, "end"))
	{
		tot = 0;
		dlx.reset(729, 324);
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				int temp = (i - 1) * 9 + j;
				if (ch[temp] == '.') a[i][j] = 0;
				else a[i][j] = ch[temp] - '0';
				if (a[i][j]) insert(i, j, a[i][j]);
				else
				{
					for (int k = 1; k <= 9; k++)
						insert(i, j, k);
				}
			}
		}
		if (dlx.dfs(0)) dlx.display();
	}
	return 0;
}

