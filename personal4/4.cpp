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
        for(int i=0;i<n;i++)//���
        {
            scanf("%d",&a);
            que.push(a);
        }
        int sum=0,x,y;
         while(que.size()>1)//�������
        {
            x=que.top();//��ȡ�������֣�Ҳ������С��
            que.pop();//����
            y=que.top();
            que.pop();
            sum+=(x+y);
            que.push(x+y);//���
        }
        cout << sum<<endl;
    
    return 0;
}

