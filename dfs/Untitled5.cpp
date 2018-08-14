#include<iostream>
#include<math.h>
using namespace std;
int a[20];
int n,k,m=0;
//判断是否是素数
bool check(int p){
    //如果是1、2、3，那就直接返回true;
    if(p==2 || p==3 || p == 1)return true;
    //不在6的倍数两侧的一定不是质数
    if(p%6 != 1 && p%6 != 5)return false;
    int q = sqrt(p);
    //6的倍数相邻的数有可能不是素数
    for(int i=5;i <= q ;i+=6){
        if(p%i == 0 || p%(i+2) == 0)return false;
    }
    //排除之后，剩下的是素数
    return true;
}
//chooseNum为还需要选几个数。
//lastSum是已选数之和
//start、end是一个区间。
int rule(int chooseNum,int lastSum,int start,int end){
    //如果已经选够k个数，那就检验k数之和是否为素数。
    if(chooseNum == 0 )return check(lastSum);
    //计数器
    int sum = 0;
    for(int i=start;i<=end;i++){
        //寻找下一个数，区间变小
        sum+=rule(chooseNum - 1,lastSum+a[i],i+1,end);
    }
    return sum;
}
int main(){
    //输入n和k
    cin>>n>>k;
    //遍历输入数组
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rule(k,0,0,n-1)<<endl;
}
