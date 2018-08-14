#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	char a[200];
	stack<char>S;
	while(~scanf("%s",a)){
		int length=strlen(a);
		for (int i = 0; i < length; ++i)
		{
			if(a[i]=='o'){
				if(S.top()=='o'){
					S.pop();
					S.push('O');
				}
				else 
					S.push(a[i]);
			}
			else{
				if(S.top()='O'){
					S.pop();
				}
				else{
					S.push(a[i])
				}
			}
		}
		char p;
		while(!S.empty()){
			p=S.top();
			S.pop();
			cout<<p;
		}
		cout<<endl;
	}

}
