#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

int main(){

	int a[1000];
	int n;
	while(cin>>n){
		int A=1,B=1;
		stack<int>S;
		int ok=1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		while(B<=n){
			if(A==a[B]){
				A++;
				B++;
			}
			else if(!S.empty()&&S.top()==a[B]){
				S.pop();
				B++;
			}
			else if(A<=n){
				S.push(A++);
			}
			else {
				ok=0;
				break;
			}
		}
		if(ok==1){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	
}
