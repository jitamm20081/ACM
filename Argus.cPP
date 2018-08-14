#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Node{
    int num,t,pre;
    Node(int nn,int tt,int pp):num(nn),t(tt),pre(pp){}//结构体定义
};


bool operator < (const Node &a,const Node&b){//重载小于号 
    if(a.pre!=b.pre) return a.pre>b.pre;//优先队列是降序排序 修改之
    else return a.num>b.num;
}

priority_queue<Node>q;
char s[20];

int main(){
    int a,b,n,i;
    while(!q.empty())q.pop();
    scanf("%s",s);
    while(strcmp(s,"#")!=0){
        scanf("%d%d",&a,&b);
        q.push(Node(a,b,b));
        scanf("%s",s);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        Node tmp= q.top();
        q.pop();
        q.push(Node(tmp.num,tmp.t,tmp.t+tmp.pre));
        printf("%d\n",tmp.num);
    }

}


