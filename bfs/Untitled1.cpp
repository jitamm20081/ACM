#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
typedef struct nn
{
    char way;//��¼·��
    int fath;//��¼���ڵ�
}node1;
typedef struct nod
{
    int aa[10];
    int n,son;//nΪ9��aa�е�λ��
}node2;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},fac[10];
node1 Node[370000];//�ڵ�
void set_fac()//����0��8�Ľײ�
{
    fac[0]=1;
    for(int i=1;i<=8;i++)
    fac[i]=fac[i-1]*i;//printf("%d",fac[8]);
}
int cantor(int aa[])//����չ��
{
    int i,j,ans=0,k;
    for(i=0;i<9;i++)
    {
        k=0;
        for(j=i+1;j<9;j++)
        if(aa[i]>aa[j])
        k++;
        ans+=k*fac[8-i];
    }
    return ans;
}
void bfs(int a[])
{
    queue<node2>Q;
    node2 q,p;
    int e,tx,ty,tem,t=0;
    for(e=0;e<9;e++) q.aa[e]=a[e];
    q.n=8;q.son=0;
    Node[q.son].fath=0;//�����ո��ڵ��Ϊ0��Ҳ���Ǳ���
    Q.push(q);
    while(!Q.empty())
    {
        q=Q.front(); Q.pop();
        for(e=0;e<4;e++)
        {
            p=q;
            tx=q.n%3+dir[e][0];ty=q.n/3+dir[e][1];
            if(tx>=0&&ty>=0&&tx<3&&ty<3)
            {
                p.n=ty*3+tx;
                tem=p.aa[p.n];p.aa[p.n]=p.aa[q.n];p.aa[q.n]=tem;
                p.son=cantor(p.aa);
                if(Node[p.son].fath==-1)//Ϊ��1ʱ��ʾ�����û�з��ʹ�����ô�������
                {
                    Node[p.son].fath=q.son;//��ǰ�ڵ�ĸ��ڵ������һ���ڵ�
                    if(e==0)Node[p.son].way='l';//һ��Ҫע���ˣ�e=0�������ߣ���������Ҫ�����ѣ�����Ϊ�������ʱ�����ٽ���ת����ֱ�Ӽ�¼�෴�ķ���
                    if(e==1)Node[p.son].way='r';
                    if(e==2)Node[p.son].way='u';
                    if(e==3)Node[p.son].way='d';
                    Q.push(p);
                }
            }
        }
    }
}
int main()
{
    int i,j,s,ss[10],a[10];
    char ch[50] ;
    for(i=0;i<9;i++)//Ŀ��
        a[i]=i+1;
    for(i=0;i<370000;i++)
    Node[i].fath=-1;
    set_fac();//����ײ�
        bfs(a);//��ʼ��Ŀ�꽨��һ��
 
    while(gets(ch)>0)
    {
        for(i=0,j=0;ch[i]!='\0';i++)//���ַ����������
        {
             if(ch[i]=='x')
            ss[j++]=9;  //��x��Ϊ����9
            else if(ch[i]>='0'&&ch[i]<='8')
            ss[j++]=ch[i]-'0';
        }
        s=cantor(ss);//�����̬����ֵ
        cout<<s; 
       if(Node[s].fath==-1) {printf("unsolvable\n");continue;}//���ܱ��Ŀ��
       
        while(s!=0)
        {
            printf("%c",Node[s].way);
            s=Node[s].fath;
        }
        printf("\n");
    }
}
/*
1 2 3 4 5 6 7 8 x
2 1  4 3 5 x 6 8 7
unsolvable
2 1  4 3 5 x 6 8 7
drdlurdruldruuldlurrdd
8 5 6 4 x 3 4 1 2
rulddruulddluurddrulldrurd
8 5 6 4 x 3 4 1 2
urdluldrurdldruulddluurddr
*/

