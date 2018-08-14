#include<iostream>

 

#include<math.h>

 

#define N 100000 //生成100000个质数

 

using namespace std;

 

int prime[N]; //一个全局数组，用来保存质数表

 

void makeprime()//生成质数表的子函数

 

{int j,n=29,i=9,sqrtn;//从第10个质数开始计算，第10个质数是29

 

    prime[0]=2;

 

    prime[1]=3;

 

    prime[2]=5;

 

    prime[3]=7;

 

    prime[4]=11;

 

    prime[5]=13;

 

    prime[6]=17;

 

    prime[7]=19;

 

    prime[8]=23; //之前已有9个质数在表中

 

    while (i<N) //i是计数变量

 

        {

 

j=0; //每次从表头开始试除

 

            sqrtn=sqrt(n); //n的平方根

 

            while (prime[j]<=sqrtn)

 

      {

 

if (n%prime[j]==0)break; //若n能整除质数表中的某数，则跳出

 

        j++;

 

}

 

             if (prime[j]>sqrtn){prime[i]=n; i++;}

 

             n+=2; //除了2，偶数不会是质数，因此跳过所有偶数

 

        }

 

}

 

int main()

 

{

 

    makeprime();

 

    for (int i=1;i<N;i++)

 

   {cout<<prime[i-1]<<" "; if (i%10==0)cout<<endl;}//每输出10个数换行

 

    system("pause");

 

    return 0;}
