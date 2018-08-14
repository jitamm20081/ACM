#include<iostream>
using namespace std;
int main()
{   
    long long fib[100];
    int n;
    int i,flag;
    fib[0]=2;
    fib[1]=3;
    for(i=2;i<100;i++)  
        fib[i]=fib[i-1]+fib[i-2];  
    while(cin>>n&&n)
    {           
        flag=0;
        for(i=0;i<100;i++)   
            if(fib[i]==n)     
            {           
                cout<<"Li\n";
                flag=1;
                break;
            }  
            if(flag==0)    
                cout<<"Han\n";   
    }   
    return 0;
}
