#include<stack>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	stack<char>s;
	char a[10000];
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int flag=0;
		scanf("%s",a);
		int length=strlen(a);
			while(!s.empty())
				s.pop();		
		for(int j=0;j<length;j++){

			if(a[j]=='{')
				s.push(a[j]);
			else{
				if(!s.empty())
					s.pop();
				else
					{
						cout<<"NO.MISSING{"<<endl;
						flag=1;
						break;
						
					}
			}
		}
		if(flag==0){
			if(s.empty())
				cout<<"YES"<<endl;
			else
				{
					cout<<"NO.MISSING}"<<endl;
				}			
		}

	}
	
	
}
