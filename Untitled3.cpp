#include<iostream>

 

#include<math.h>

 

#define N 100000 //����100000������

 

using namespace std;

 

int prime[N]; //һ��ȫ�����飬��������������

 

void makeprime()//������������Ӻ���

 

{int j,n=29,i=9,sqrtn;//�ӵ�10��������ʼ���㣬��10��������29

 

    prime[0]=2;

 

    prime[1]=3;

 

    prime[2]=5;

 

    prime[3]=7;

 

    prime[4]=11;

 

    prime[5]=13;

 

    prime[6]=17;

 

    prime[7]=19;

 

    prime[8]=23; //֮ǰ����9�������ڱ���

 

    while (i<N) //i�Ǽ�������

 

        {

 

j=0; //ÿ�δӱ�ͷ��ʼ�Գ�

 

            sqrtn=sqrt(n); //n��ƽ����

 

            while (prime[j]<=sqrtn)

 

      {

 

if (n%prime[j]==0)break; //��n�������������е�ĳ����������

 

        j++;

 

}

 

             if (prime[j]>sqrtn){prime[i]=n; i++;}

 

             n+=2; //����2��ż�������������������������ż��

 

        }

 

}

 

int main()

 

{

 

    makeprime();

 

    for (int i=1;i<N;i++)

 

   {cout<<prime[i-1]<<" "; if (i%10==0)cout<<endl;}//ÿ���10��������

 

    system("pause");

 

    return 0;}
