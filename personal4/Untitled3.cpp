#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn];
int m[maxn];
int f[maxn];

bool judge(int n, int k){
    for(int i = 0; i <= k; i++){
        f[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int t = 1;
        while(m[i] > 0){
            if(t > m[i]){
                t = m[i];
            }
            m[i] = m[i] - t;

            for(int j = k; j >= a[i] * t; j--){
                f[j] = max(f[j], f[j - t * a[i]] + t * a[i]);
            }
            t *= 2;
        }
    }
    for(int j = 0; j <= k; j++){
        if(f[j] == k)
            return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d",&m[i]);
        }
        scanf("%d",&k);
        if(judge(n, k)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
