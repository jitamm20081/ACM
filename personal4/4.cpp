#include <string.h>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,a;
    priority_queue<int,vector<int>,greater<int> >que;
   scanf("%d",&n);
        for(int i=0;i<n;i++)//入队
        {
            scanf("%d",&a);
            que.push(a);
        }
        int sum=0,x,y;
         while(que.size()>1)//出队求和
        {
            x=que.top();//获取顶端数字，也就是最小的
            que.pop();//出队
            y=que.top();
            que.pop();
            sum+=(x+y);
            que.push(x+y);//入队
        }
        cout << sum<<endl;
    
    return 0;
}

