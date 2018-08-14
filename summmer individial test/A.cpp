#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	while(cin>>n){
		if(n==1){
			printf("1/1\n");
			continue;}
		int i=1;
		int sum;
		while(1){
			if(((i+1)*i/2+i+1)>=n)
				break;
			i++;
		}
		i++;
		if(i%2==0)
		{
			sum=(i+1)*i/2-n;
			printf("%d/%d\n",i-sum,1+sum);
		}
		else{
			sum=(i+1)*i/2-n;
			printf("%d/%d\n",1+sum,i-sum);
		}

	}
}