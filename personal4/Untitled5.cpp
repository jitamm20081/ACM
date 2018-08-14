#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 101 

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;//从小到大排序 
}
/* 
int cmp(const void *a, const void *b)
{
    return *(int *)b- *(int *)a;//从大到小排序 
}
*/ 
int main()
{
    char a[maxn];
    char b[maxn];
    while(scanf("%s%s",&a,&b) != EOF)
    {
        int len = strlen(a);
        int cnt1[26],cnt2[26];
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));

        for(int i=0; i < len; i++)
        {
            cnt1[a[i] - 'A']++; //A-0 B-1..... 
            cnt2[b[i] - 'A']++;
        }

        //排序
        qsort(cnt1,26,sizeof(cnt1[0]),cmp);//qsort快速排序 
        qsort(cnt2,26,sizeof(cnt2[0]),cmp);

        for(int i=0; i < 26; i++)
        {
            if(cnt1[i] != cnt2[i])
            {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
    }

    return 0;
}
