#include<iostream>
#include<math.h>
using namespace std;
int a[20];
int n,k,m=0;
//�ж��Ƿ�������
bool check(int p){
    //�����1��2��3���Ǿ�ֱ�ӷ���true;
    if(p==2 || p==3 || p == 1)return true;
    //����6�ı��������һ����������
    if(p%6 != 1 && p%6 != 5)return false;
    int q = sqrt(p);
    //6�ı������ڵ����п��ܲ�������
    for(int i=5;i <= q ;i+=6){
        if(p%i == 0 || p%(i+2) == 0)return false;
    }
    //�ų�֮��ʣ�µ�������
    return true;
}
//chooseNumΪ����Ҫѡ��������
//lastSum����ѡ��֮��
//start��end��һ�����䡣
int rule(int chooseNum,int lastSum,int start,int end){
    //����Ѿ�ѡ��k�������Ǿͼ���k��֮���Ƿ�Ϊ������
    if(chooseNum == 0 )return check(lastSum);
    //������
    int sum = 0;
    for(int i=start;i<=end;i++){
        //Ѱ����һ�����������С
        sum+=rule(chooseNum - 1,lastSum+a[i],i+1,end);
    }
    return sum;
}
int main(){
    //����n��k
    cin>>n>>k;
    //������������
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rule(k,0,0,n-1)<<endl;
}
