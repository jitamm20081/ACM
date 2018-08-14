#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
	int a,b;
	int used[1001],first[1001],m[1001];
	
	while(cin>>a>>b){
		memset(used,0,sizeof(used));
		int count=0;
		if(a==0&&b==0)
			break;
		while(!used[a]&&a){
			used[a]=1;
			m[count]=a*10/b;
			first[a]=count++;
			a=a*10%b;
		}
		cout<<".";
		for(int i=0;i<count;i++)
			{	
				if((i+1)%50==0)
				cout<<endl;
				cout<<m[i];
			
			}
			cout<<endl;
		if(!used[a])
			printf("This expansion terminates.\n");
		else
			printf("The last %d digits repeat forever.\n",count-first[a]);
		
		
	}
	
}
