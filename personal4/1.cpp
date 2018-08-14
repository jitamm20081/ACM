#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	char a[200];
	stack<char>S;
	while(~scanf("%s",a)){
		while(!S.empty())S.pop();
		int length=strlen(a);
		for (int i = 0; i < length; ++i)
		{
			
			if(S.empty()){
				S.push(a[i]);
				continue;
			}
			if(a[i]=='o'){
				if(S.top()=='o'){
					S.pop();
					S.push('O');
				} 
				else {
					S.push(a[i]);
				}
			}
			else {
				if(S.top()=='O'){
					S.pop();
				}
				else{
					S.push(a[i]);
				}
			}
		}
	/*	while(!S.empty()){
			char k;
			k=S.top();
			S.pop();
			cout<<k;
		}
		*/
		stack<char>S2;
		while(!S.empty()){
			char m;
			m=S.top();
			S.pop();
			if(!S.empty()){
				if(S.top()==m&&S.top()=='O'){
					S.pop();
				}
				else {
					S2.push(m);
				}				
			}
			else S2.push(m);

				
		}
		char p;
		while(!S2.empty()){
			p=S2.top();
			S2.pop();
			cout<<p;
		}
		cout<<endl;
}

}
