#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>S;
	int a[1000];
	int b[1000];
	int n;
	while(cin>>n){
		while(!S.empty())S.pop();
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		int p=b[0];
		for(int i=1;i<=p;i++){
			S.push(i);
		}
		
		int flag=0;
		
		if(flag==1)
			cout<<"No"<<endl;
		else 
			cout<<"Yes"<<endl;
	} 
} 
