#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e3+5;
const int N = 20005;
#define ll long long

int t, m, n;
int c[N], v[N], dp[N];

int main()
{
    while(cin >> m >> n)
    {
        for(int i=1;i<=n;i++)
            cin >> v[i];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=m; j>=v[i]; j--){
                dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
            }
        }
        cout << m-dp[m] << endl; 
    }
}
