#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[100005];
int a[15];
vector<int>v;
int main(){
    int cash;
    int n,m,x;
    while(scanf("%d%d",&cash,&n)!=EOF){
        memset(dp,0, sizeof(dp));
        v.clear();
        dp[0]=1;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&m,&x);
            for (int j = 1; j <= m; j<<=1) {//二进制优化
                v.push_back(j*x);
                m-=j;
            }
            if(m>0) v.push_back(m*x);//别忘了剩余的数
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = cash; j >=v[i] ; --j) {
                dp[j]=max(dp[j-v[i]],dp[j]);
            }
        }
        for (int i = cash; i >= 0 ; --i) {
            if(dp[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}